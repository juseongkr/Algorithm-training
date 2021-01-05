#include <iostream>
using namespace std;
#define MAX 1000001

int n;
int dp[MAX];

int solve(int n)
{
	if (n == 1)
		return 0;

	if (~dp[n])
		return dp[n];

	int ret = solve(n-1) + 1;
	if (n % 3 == 0)
		ret = min(ret, solve(n/3) + 1);
	if (n % 2 == 0)
		ret = min(ret, solve(n/2) + 1);
	
	return dp[n] = ret;
}

int main()
{
	cin >> n;

	fill(dp, dp+MAX, -1);
	cout << solve(n) << '\n';

	return 0;
}
