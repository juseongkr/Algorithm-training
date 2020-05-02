#include <iostream>
#include <cstring>
using namespace std;
#define MAX 13

int n, m, c;
int wei[MAX];
int dp[11][21][(1 << MAX)];

int solve(int bag, int sz, int bit)
{
	if (bag == m || (bit == (1 << MAX)-1))
		return 0;

	if (~dp[bag][sz][bit])
		return dp[bag][sz][bit];

	dp[bag][sz][bit] = solve(bag+1, 0, bit);
	for (int i=0; i<n; ++i) {
		if (sz + wei[i] <= c && !(bit & (1 << i)))
			dp[bag][sz][bit] = max(dp[bag][sz][bit], solve(bag, sz + wei[i], bit | (1 << i)) + 1);
	}

	return dp[bag][sz][bit];
}

int main()
{
	cin >> n >> m >> c;
	for (int i=0; i<n; ++i)
		cin >> wei[i];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0, 0) << '\n';

	return 0;
}
