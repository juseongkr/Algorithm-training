#include <iostream>
#include <cstring>
using namespace std;
#define MAX 50001

int n;
int dp[MAX];

int solve(int cur)
{
	if (cur == 0)
		return 0;
	else if (cur == 1)
		return 1;

	if (~dp[cur])
		return dp[cur];

	dp[cur] = cur;
	for (int i=0; i*i<=cur; ++i)
		dp[cur] = min(dp[cur], solve(cur-i*i) + 1);

	return dp[cur];
}

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << solve(n) << '\n';

	return 0;
}
