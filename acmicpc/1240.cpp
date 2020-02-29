#include <iostream>
#include <vector>
using namespace std;
#define MAX 1001
#define DEP 20

int n, m, x, y, z, ans;
vector<pair<int, int>> graph[MAX];
long long dist[MAX];
int parent[MAX][DEP];
int depth[MAX];

void dfs(int cur, int prev, int dis)
{
	dist[cur] = dis;
	depth[cur] = depth[prev] + 1;
	parent[cur][0] = prev;
	for (int i=1; i<DEP; ++i)
		parent[cur][i] = parent[parent[cur][i-1]][i-1];

	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i].first;
		int cost = graph[cur][i].second;
		if (next != prev)
			dfs(next, cur, dis + cost);
	}
}

int lca(int a, int b)
{
	if (depth[a] > depth[b])
		swap(a, b);

	for (int i=DEP-1; i>=0; i--)
		if (depth[a] <= depth[parent[b][i]])
			b = parent[b][i];

	int lca = a;
	if (a != b) {
		for (int i=DEP-1; i>=0; i--) {
			if (parent[a][i] != parent[b][i]) {
				a = parent[a][i];
				b = parent[b][i];
			}
		}
		lca = parent[a][0];
	}
	return lca;
}

long long distance(int a, int b)
{
	return dist[a] + dist[b] - (dist[lca(a, b)] * 2);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n-1; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}

	dfs(1, 0, 0);

	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		cout << distance(x, y) << '\n';
	}

	return 0;
}
