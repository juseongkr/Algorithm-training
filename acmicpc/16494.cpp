#include <iostream>
#include <cstring>
using namespace std;
#define MAX 21

int n, m;
int num[MAX];
int dp[MAX][MAX];

int solve(int cur, int val)
{
	if (val == m)
		return 0;

	if (cur == n)
		return -1e9+7;

	if (dp[cur][val] != -1)
		return dp[cur][val];

	int t = 0;
	dp[cur][val] = solve(cur+1, val);
	for (int i=cur; i<n; ++i) {
		t += num[i];
		dp[cur][val] = max(dp[cur][val], solve(i+1, val+1) + t);
	}

	return dp[cur][val];
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';

	return 0;
}
