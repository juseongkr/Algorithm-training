#include <iostream>
#include <vector>
using namespace std;
#define MAX 1001
const int INF = 1e9+7;

vector<pair<int, int>> graph[MAX];

int dfs(int prev, int cur, int dist)
{
	int ret = 0;
	for (int i=0; i<graph[cur].size(); ++i) {
		auto [next, cost] = graph[cur][i];
		if (prev != next)
			ret += dfs(cur, next, cost);
	}

	if (ret == 0)
		return dist;

	return min(ret, dist);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, m, t, x, y, z;

	cin >> t;
	while (t--) {
		cin >> n >> m;
		if (m == 0) {
			cout << "0\n";
			continue;
		}

		for (int i=0; i<m; ++i) {
			cin >> x >> y >> z;
			graph[x].push_back({y, z});
			graph[y].push_back({x, z});
		}

		cout << dfs(0, 1, INF) << '\n';

		for (int i=0; i<=n; ++i)
			graph[i].clear();
	}

	return 0;
}
