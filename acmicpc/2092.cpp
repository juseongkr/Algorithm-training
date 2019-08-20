#include <iostream>
#include <cstring>
using namespace std;
#define MAX 201
#define MOD 1000000

int t, n, s, b, k;
int num[MAX];
int dp[MAX][4001];

int solve(int n, int k)
{
	if (n <= 0 || k < 0)
		return 0;

	if (dp[n][k] != -1)
		return dp[n][k];

	dp[n][k] = 0;
	if (k <= num[n])
		dp[n][k]++;

	for (int i=0; i<=num[n]; ++i) {
		if (k - i > 0) {
			dp[n][k] += solve(n-1, k-i);
			dp[n][k] %= MOD;
		}
	}

	return dp[n][k];
}

int main()
{
	cin >> t >> n >> s >> b;
	for (int i=0; i<n; ++i) {
		cin >> k;
		num[k]++;
	}

	int ans = 0;
	memset(dp, -1, sizeof(dp));
	for (int i=s; i<=b; ++i) {
		ans += solve(t, i);
		ans %= MOD;
	}
	cout << ans << '\n';

	return 0;
}
