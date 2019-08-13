#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001
#define DEP 18

vector<int> graph[MAX];
int depth[MAX], parent[MAX][DEP];
int n, m, r, u, v;

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

int lca(int u, int v)
{
	if (depth[u] > depth[v])
		swap(u, v);

	for (int i=DEP-1; i>=0; i--)
		if (depth[u] <= depth[parent[v][i]])
			v = parent[v][i];

	int lca = u;
	if (u != v) {
		for (int i=DEP-1; i>=0; i--) {
			if (parent[u][i] != parent[v][i]) {
				u = parent[u][i];
				v = parent[v][i];
			}
		}
		lca = parent[u][0];
	}
	return lca;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i=0; i<n-1; ++i) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1, 0);

	cin >> m;
	while (m--) {
		cin >> r >> u >> v;

		int x = lca(r, u);
		int y = lca(u, v);

		if (depth[x] < depth[y])
			x = y;

		y = lca(r, v);
		if (depth[x] < depth[y])
			x = y;

		cout << x << '\n';
	}

	return 0;
}
