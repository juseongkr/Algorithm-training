#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 101
const int INF = 1e9+7;

int n, m, x, y, t;
int h[MAX];
int dp[MAX][1001];
vector<int> graph[MAX];

int solve(int cur, int k)
{
	if (k == 0)
		return h[cur];

	if (dp[cur][k] != -1)
		return dp[cur][k];

	dp[cur][k] = INF;
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		dp[cur][k] = min(dp[cur][k], solve(next, k-1));
	}
	return dp[cur][k];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=1; i<=n; ++i)
		cin >> h[i];

	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	cin >> t;
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<t; ++i) {
		cin >> x >> y;
		
		int ret = solve(x, y);
		if (ret == INF)
			cout << "-1\n";
		else
			cout << ret << '\n';
	}

	return 0;
}
