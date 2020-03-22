#include <iostream>
#include <vector>
using namespace std;
#define MAX 50001
const int INF = 1e9+7;

int n, x, y, z, far, mx;
int dist[MAX], ans[MAX];
vector<pair<int, int>> graph[MAX];

void dfs(int cur, int d)
{
	dist[cur] = d;
	if (mx < dist[cur]) {
		mx = dist[cur];
		far = cur;
	}

	for (int i=0; i<graph[cur].size(); ++i) {
		auto [next, cost] = graph[cur][i];
		if (dist[next] == INF)
			dfs(next, d + cost);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n-1; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}

	mx = 0;
	fill(dist, dist+MAX, INF);
	dfs(1, 0);

	mx = 0;
	fill(dist, dist+MAX, INF);
	dfs(far, 0);

	for (int i=1; i<=n; ++i)
		ans[i] = dist[i];

	fill(dist, dist+MAX, INF);
	dfs(far, 0);

	for (int i=1; i<=n; ++i)
		cout << max(ans[i], dist[i]) << '\n';

	return 0;
}
