#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1000001
const int MOD = 1e6;

int n;
int dp[MAX][5];

int solve(int cur, int num)
{
	if (cur > n)
		return 0;
	if (cur == n)
		return num == 0;

	if (~dp[cur][num])
		return dp[cur][num];

	dp[cur][num] = 0;
	if (num == 0) {
		dp[cur][num] = solve(cur+1, 1)*2 + \
			       solve(cur+1, 2) + \
			       solve(cur+2, 3)*4 + \
			       solve(cur+2, 4)*2;
	} else if (num == 1) {
		dp[cur][num] = solve(cur+3, 0)*2 + \
			       solve(cur+4, 1) + \
			       solve(cur+4, 2) + \
			       solve(cur+1, 3)*2 + \
			       solve(cur+5, 3)*2;
	} else if (num == 2) {
		dp[cur][num] = solve(cur+3, 0)*2;
	} else if (num == 3) { 
		dp[cur][num] = solve(cur+2, 0) + \
			       solve(cur+3, 1)*2 + \
			       solve(cur+3, 2) + \
			       solve(cur+4, 3);
	} else if (num == 4) {
		dp[cur][num] = solve(cur+2, 0) + \
			       solve(cur+3, 1)*2 + \
			       solve(cur+3, 2)*2 + \
			       solve(cur+4, 3)*2;
	}
	return dp[cur][num] %= MOD;
} 

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';

	return 0;
}
