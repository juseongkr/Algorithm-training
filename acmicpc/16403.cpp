#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 10001

int n, a, b;
int block[MAX];
long long dp[MAX][41];

long long solve(int cur, int bus)
{
	if (dp[cur][bus] != -1)
		return dp[cur][bus];

	long long ret = 0;
	if (bus > 0) {
		for (int i=0; i<bus; ++i)
			ret += abs(block[cur-i-1] - block[cur-bus/2-1]) * a;
		ret += b;
	}
	if (cur == n)
		return dp[cur][bus] = ret;

	dp[cur][bus] = min(solve(cur+1, 0) + a * block[cur], solve(cur+1, 1)) + ret;
	if (bus < 40)
		dp[cur][bus] = min(dp[cur][bus], solve(cur+1, bus+1));

	return dp[cur][bus];
}

int main()
{
	cin >> n >> a >> b;
	for (int i=0; i<n; ++i)
		cin >> block[i];

	sort(block, block+n);
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';

	return 0;
}
