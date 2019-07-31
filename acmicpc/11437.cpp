#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001
#define DEP 18

int n, m, a, b;
vector<int> graph[MAX];
int parent[MAX][DEP];
int depth[MAX];

void dfs(int cur, int prev)
{
	depth[cur] = depth[prev] + 1;
	parent[cur][0] = prev;
	for (int i=1; i<DEP; ++i)
		parent[cur][i] = parent[parent[cur][i-1]][i-1];

	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (next != prev)
			dfs(next, cur);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i=0; i<n-1; ++i) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1, 0);

	cin >> m;
	for (int i=0; i<m; ++i) {
		cin >> a >> b;

		if (depth[a] > depth[b])
			swap(a, b);

		for (int i=DEP-1; i>=0; i--)
			if (depth[a] <= depth[parent[b][i]])
				b = parent[b][i];

		if (a != b) {
			for (int i=DEP-1; i>=0; i--) {
				if (parent[a][i] && parent[a][i] != parent[b][i]) {
					a = parent[a][i];
					b = parent[b][i];
				}
			}
			a = parent[a][0];
		}
		cout << a << '\n';
	}

	return 0;
}
