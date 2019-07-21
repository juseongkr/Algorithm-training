#include <iostream>
#include <cstring>
using namespace std;
#define MAX 50001

int dp[MAX][3];
int num[MAX];
int n, k;

int solve(int cur, int train)
{
	if (cur == n || train == 3)
		return 0;

	if (dp[cur][train] != -1)
		return dp[cur][train];

	dp[cur][train] = 0;
	if (cur + k <= n+1)
		dp[cur][train] = max(solve(cur+1, train), num[cur+k-1] - num[cur-1] + solve(cur+k, train+1));
	return dp[cur][train];
}

int main()
{
	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> num[i];
		num[i] = num[i-1] + num[i];
	}
	cin >> k;

	memset(dp, -1, sizeof(dp));
	cout << solve(1, 0) << '\n';

	return 0;
}
