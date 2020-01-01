#include <iostream>
#include <vector>
using namespace std;
#define MAX 1001
const int INF = 1e9+7;
typedef pair<int, int> pii;

int n, q, x, y, z;
int dist[MAX][MAX];
vector<pii> graph[MAX];

void dfs(int cur, int next, int cost)
{
	dist[cur][next] = cost;
	for (int i=0; i<graph[next].size(); ++i) {
		auto [c, go] = graph[next][i];
		if (dist[cur][go] > cost + c)
			dfs(cur, go, cost + c);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> q;
	for (int i=0; i<n-1; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back({z, y});
		graph[y].push_back({z, x});
	}

	for (int i=0; i<MAX; ++i)
		for (int j=0; j<MAX; ++j)
			dist[i][j] = INF;

	for (int i=1; i<=n; ++i)
		dfs(i, i, 0);

	for (int i=0; i<q; ++i) {
		cin >> x >> y;
		cout << dist[x][y] << '\n';
	}

	return 0;
}
