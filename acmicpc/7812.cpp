#include <iostream>
#include <vector>
using namespace std;
#define MAX 10001
const long long INF = 1e18+7;

long long ans;
int n, x, y, z;
vector<pair<int, int>> graph[MAX];
bool visit[MAX];

int dfs(int cur)
{
	visit[cur] = 1;
	int ret = 1;

	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i].first;
		int next_cost = graph[cur][i].second;

		if (visit[next])
			continue;

		int val = dfs(next);

		ret += val;
		ans += next_cost * min(val, n - val);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	while (1) {
		cin >> n;
		if (n == 0)
			break;

		fill(visit, visit+n, 0);
		for (int i=0; i<n; ++i)
			graph[i].clear();

		for (int i=0; i<n-1; ++i) {
			cin >> x >> y >> z;
			graph[x].push_back({y, z});
			graph[y].push_back({x, z});
		}

		ans = 0;
		dfs(0);

		cout << ans << '\n';
	}

	return 0;
}
