#include <iostream>
using namespace std;
#define MAX 101
#define MOD 1000000000

int n;
int dp[MAX][10][1<<10];
long long ans;

int solve(int cur, int last, int visit)
{
	if (cur == n) {
		if (visit == (1 << 10) - 1)
			return 1;
		else
			return 0;
	}

	if (dp[cur][last][visit])
		return dp[cur][last][visit];

	if (last < 9) {
		dp[cur][last][visit] += solve(cur+1, last+1, visit | (1 << (last+1)));
		dp[cur][last][visit] %= MOD;
	}
	if (last > 0) {
		dp[cur][last][visit] += solve(cur+1, last-1, visit | (1 << (last-1)));
		dp[cur][last][visit] %= MOD;
	}

	return dp[cur][last][visit];
}

int main()
{
	cin >> n;
	for (int i=1; i<10; ++i) {
		ans += solve(1, i, (1 << i));
		ans %= MOD;
	}
	cout << ans << '\n';

	return 0;
}
