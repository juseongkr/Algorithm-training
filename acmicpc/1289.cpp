#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001
const long long MOD = 1e9+7;

long long ans;
vector<pair<int, int>> graph[MAX];

long long dfs(int cur, int prev)
{
	int ret = 1;
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i].first;
		int cost = graph[cur][i].second;
		if (next != prev) {
			long long val = (dfs(next, cur) * cost) % MOD;
			ans = (ans + val * ret) % MOD;
			ret = (ret + val) % MOD;
		}
	}
	return ret;
}

int main()
{
	int n, a, b, c;

	cin >> n;
	for (int i=1; i<n; ++i) {
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	dfs(1, 0);

	cout << ans << '\n';

	return 0;
}
