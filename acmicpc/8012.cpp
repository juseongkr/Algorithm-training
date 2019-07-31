#include <iostream>
#include <vector>
using namespace std;
#define MAX 30001
#define DEP 15

int n, m, a, b;
vector<int> graph[MAX];
int depth[MAX], parent[MAX][DEP], dist[MAX];

void dfs(int cur, int prev, int dis)
{
	dist[cur] = dis;
	depth[cur] = depth[prev] + 1;
	parent[cur][0] = prev;
	for (int i=1; i<DEP; ++i)
		parent[cur][i] = parent[parent[cur][i-1]][i-1];

	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (next != prev)
			dfs(next, cur, dis+1);
	}
}

int main()
{
	cin >> n;
	for (int i=0; i<n-1; ++i) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1, 0, 0);
	
	cin >> m;
	int ans = 0;
	int a = 1;
	while (m--) {
		cin >> b;
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
		ans += dist[A] + dist[B] - (dist[lca]*2);
		a = B;
	}
	cout << ans << '\n';

	return 0;
}
