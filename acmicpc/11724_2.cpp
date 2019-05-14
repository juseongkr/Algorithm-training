#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[1001];
int visit[1001];

void dfs(int n)
{
	visit[n] = 1;
	for (int i=0; i<graph[n].size(); ++i) {
		int next = graph[n][i];
		if (!visit[next])
			dfs(next);
	}
}

int main()
{
	int n, m, a, b;

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int cnt = 0;
	for (int i=1; i<=n; ++i) {
		if (!visit[i]) {
			dfs(i);
			cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}
