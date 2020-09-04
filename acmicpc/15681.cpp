#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001

int n, r, q, x, y;
vector<int> graph[MAX];
bool visit[MAX];
int node[MAX];

int dfs(int cur)
{
	visit[cur] = 1;
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (!visit[next])
			node[cur] += dfs(next) + 1;
	}

	return node[cur];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> r >> q;
	for (int i=0; i<n-1; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(r);

	while (q--) {
		cin >> x;
		cout << node[x] + 1 << '\n';
	}

	return 0;
}
