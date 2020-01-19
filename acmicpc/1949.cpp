#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 10001

int n, x, y, k;
int dp[MAX][2];
bool visit[MAX];
vector<int> num, graph[MAX], child[MAX];

void dfs(int cur)
{
	visit[cur] = 1;
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (!visit[next]) {
			child[cur].push_back(next);
			dfs(next);
		}
	}
}

int solve(int cur, bool f)
{
	if (cur == n)
		return 0;

	if (~dp[cur][f])
		return dp[cur][f];
	
	dp[cur][f] = f ? num[cur] : 0;
	for (int i=0; i<child[cur].size(); ++i) {
		int next = child[cur][i];
		int val = solve(next, false);
		if (!f)
			val = max(val, solve(next, true));
		dp[cur][f] += val;
	}

	return dp[cur][f];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> k;
		num.push_back(k);
	}

	for (int i=0; i<n-1; ++i) {
		cin >> x >> y;
		x--;
		y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(0);

	memset(dp, -1, sizeof(dp));
	cout << max(solve(0, 1), solve(0, 0)) << '\n';

	return 0;
}
