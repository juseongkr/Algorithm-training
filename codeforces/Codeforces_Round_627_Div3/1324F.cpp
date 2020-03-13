#include <iostream>
#include <vector>
using namespace std;
#define MAX 200001

int n, x, y;
vector<int> graph[MAX];
bool col[MAX];
int dp[MAX];

void dfs(int cur, int prev)
{
	if (col[cur])
		dp[cur] = 1;
	else
		dp[cur] = -1;

	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (next == prev)
			continue;

		dfs(next, cur);
		dp[cur] += max(0, dp[next]);
	}
}

void dfs2(int cur, int prev)
{
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (next == prev)
			continue;
		if (dp[next] > 0)
			dp[next] += max(0, dp[cur]-dp[next]);
		else
			dp[next] += max(0, dp[cur]);
		dfs2(next, cur);
	}
}

int main()
{
	cin >> n;
	for (int i=1; i<=n; ++i)
		cin >> col[i];

	for (int i=0; i<n-1; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(1, 1);
	dfs2(1, 1);

	for (int i=1; i<=n; ++i)
		cout << dp[i] << " ";

	return 0;
}
