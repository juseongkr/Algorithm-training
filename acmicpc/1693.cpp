#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 100001
#define COL 20
const int INF = 1e9+7;

int n, x, y;
int dp[MAX][COL];
vector<int> graph[MAX], tree[MAX];
bool visit[MAX];

void dfs(int cur)
{
	visit[cur] = 1;
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (!visit[next]) {
			tree[cur].push_back(next);
			dfs(next);
		}
	}
}

int solve(int cur, int col)
{
	if (~dp[cur][col])
		return dp[cur][col];

	dp[cur][col] = INF;
	for (int i=1; i<=COL; ++i) {
		if (col != i) {
			int ret = i;
			for (int j=0; j<tree[cur].size(); ++j) {
				int next = tree[cur][j];
				ret += solve(next, i);
			}
			dp[cur][col] = min(dp[cur][col], ret);
		}
	}

	return dp[cur][col];
}

int main()
{
	cin >> n;
	for (int i=0; i<n-1; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(1);

	memset(dp, -1, sizeof(dp));
	cout << solve(1, 0) << '\n';

	return 0;
}
