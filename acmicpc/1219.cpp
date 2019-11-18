#include <iostream>
#include <vector>
using namespace std;
#define MAX 101
const int INF = 1e9+7;

vector<pair<int, int>> graph[MAX];
long long cost[MAX], dist[MAX];
bool mat[MAX][MAX];

int main()
{
	int n, m, s, e, x, y, z;

	cin >> n >> s >> e >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
		mat[x][y] = 1;
	}

	for (int i=0; i<n; ++i) {
		cin >> cost[i];
		mat[i][i] = 1;
	}

	for (int k=0; k<n; ++k)
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				if (mat[i][k] && mat[k][j])
					mat[i][j] = 1;

	bool cycle = false;
	fill(dist, dist+MAX, INF);
	dist[s] = -cost[s];
	for (int k=0; k<n; ++k) {
		for (int i=0; i<n; ++i) {
			for (int j=0; j<graph[i].size(); ++j) {
				int next = graph[i][j].first;
				long long next_cost = graph[i][j].second - cost[next];

				if (dist[i] != INF && dist[next] > dist[i] + next_cost) {
					dist[next] = dist[i] + next_cost;
					if (k == n-1 && mat[next][e])
						cycle = true;
				}
			}
		}
	}

	if (cycle)
		cout << "Gee\n";
	else if (dist[e] == INF)
		cout << "gg\n";
	else
		cout << -dist[e] << '\n';

	return 0;
}
