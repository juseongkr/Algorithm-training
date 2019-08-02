#include <iostream>
#include <climits>
#include <vector>
using namespace std;
#define MAX 100001
#define DEP 18

int n, m, a, b, c;
vector<pair<int, int>> graph[MAX];
int parent[MAX][DEP], depth[MAX];
int max_val[MAX][DEP], min_val[MAX][DEP];

void dfs(int cur, int prev, int val)
{
	min_val[cur][0] = val;
	max_val[cur][0] = val;
	depth[cur] = depth[prev] + 1;
	parent[cur][0] = prev;
	for (int i=1; i<DEP; ++i)
		parent[cur][i] = parent[parent[cur][i-1]][i-1];

	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i].first;
		int cost = graph[cur][i].second;
		if (next != prev)
			dfs(next, cur, cost);

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

	for(int j=1; j<DEP; j++){
		for(int i=1; i<=n; i++){
			min_val[i][j] = min(min_val[i][j-1], min_val[parent[i][j-1]][j-1]);
			max_val[i][j] = max(max_val[i][j-1], max_val[parent[i][j-1]][j-1]);
		}
	}

	cin >> m;
	while (m--) {
		cin >> a >> b;
		int mi = INT_MAX, mx = 0;
		if (depth[a] > depth[b])
			swap(a, b);

		for (int i=DEP-1; i>=0; i--) {
			if (depth[a] <= depth[parent[b][i]]) {
				mi = min(mi, min_val[b][i]);
				mx = max(mx, max_val[b][i]);
				b = parent[b][i];
			}
		}

		int lca = a;
		if (a != b) {
			for (int i=DEP-1; i>=0; i--) {
				if (parent[a][i] != parent[b][i]) {
					mi = min(mi, min(min_val[a][i], min_val[b][i]));
					mx = max(mx, max(max_val[a][i], max_val[b][i]));
					a = parent[a][i];
					b = parent[b][i];
				}
			}
			lca = parent[a][0];
		}

		if (a != lca) {
			mi = min(mi, min(min_val[a][0], min_val[b][0]));
			mx = max(mx, max(max_val[a][0], max_val[b][0]));
		}

		cout << mi << " " << mx << '\n';
	}

	return 0;
}
