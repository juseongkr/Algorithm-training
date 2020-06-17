#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 10001

int dp[MAX];
int n, d, x, y, z;
vector<pair<int, int>> graph[MAX];

int solve(int cur)
{
	if (cur == d)
		return 0;

	if (~dp[cur])
		return dp[cur];

	dp[cur] = solve(cur+1) + 1;
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i].first;
		int cost = graph[cur][i].second;
		dp[cur] = min(dp[cur], solve(next) + cost);
	}

	return dp[cur];
}

int main()
{
	cin >> n >> d;
	for (int i=0; i<n; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(0) << '\n';

	return 0;
}
