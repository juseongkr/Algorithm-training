#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 10001
#define DEP 14

vector<int> graph[MAX];
int depth[MAX], parent[MAX][DEP];
int root[MAX];
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

	int t, n, a, b;

	cin >> t;
	while (t--) {
		cin >> n;

		fill(depth, depth+MAX, 0);
		fill(root, root+MAX, 0);
		memset(parent, 0, sizeof(parent));
		for (int i=0; i<MAX; ++i)
			graph[i].clear();

		for (int i=0; i<n-1; ++i) {
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
			root[b] = a;
		}

		int r = 0;
		for (int i=1; i<=n; ++i) {
			if (root[i] == 0) {
				r = i;
				break;
			}
		}

		dfs(r, 0);

		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}

	return 0;
}
