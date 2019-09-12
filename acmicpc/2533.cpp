#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 1000001

int n, a, b;
int visit[MAX], dp[MAX][2];
vector<int> graph[MAX];

int dfs(int cur, bool check)
{
	visit[cur] = 1;

	if (check && dp[cur][0] != -1)
		return dp[cur][0];

	if (!check && dp[cur][1] != -1)
		return dp[cur][1];

	dp[cur][0] = 1;
	dp[cur][1] = 0;

	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (!visit[next]) {
			dp[cur][0] += min(dfs(next, true), dfs(next, false));
			dp[cur][1] += dfs(next, true);
		}
	}

	if (check)
		return dp[cur][0];
	else
		return dp[cur][1];
}

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<n-1; ++i) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cout << min(dfs(1, true), dfs(1, false)) << '\n';

	return 0;
}
