#include <iostream>
#include <vector>
using namespace std;
#define MAX 40001
#define DEP 20

int n, m, a, b, c;
vector<pair<int, int>> graph[MAX];
int parent[MAX][DEP];
int depth[MAX];
long long dist[MAX];

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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i=0; i<n-1; ++i) {
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}
	
	dfs(1, 0, 0);

	cin >> m;
	while (m--) {
		cin >> a >> b;
		int A = a, B = b;
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
		cout << dist[A] + dist[B] - (dist[lca] * 2) << '\n';
	}

	return 0;
}
