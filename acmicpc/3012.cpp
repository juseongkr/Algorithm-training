#include <iostream>
#include <cstring>
using namespace std;
#define MAX 201
#define MOD 100000

int n;
string s;
long long dp[MAX][MAX];

long long solve(int a, int b)
{
	if (a > b)
		return 1;

	if (dp[a][b] != -1)
		return dp[a][b];

	dp[a][b] = 0;
	for (int k=a+1; k<=b; k+=2) {
		if ((s[a] == '(' || s[a] == '?') && (s[k] == ')' || s[k] == '?')) {
			dp[a][b] += solve(a+1, k-1) * solve(k+1, b);
			if (dp[a][b] >= MOD)
				dp[a][b] = MOD + dp[a][b] % MOD;
		}

		if ((s[a] == '{' || s[a] == '?') && (s[k] == '}' || s[k] == '?')) {
			dp[a][b] += solve(a+1, k-1) * solve(k+1, b);
			if (dp[a][b] >= MOD)
				dp[a][b] = MOD + dp[a][b] % MOD;
		}

		if ((s[a] == '[' || s[a] == '?') && (s[k] == ']' || s[k] == '?')) {
			dp[a][b] += solve(a+1, k-1) * solve(k+1, b);
			if (dp[a][b] >= MOD)
				dp[a][b] = MOD + dp[a][b] % MOD;
		}
	}
	return dp[a][b];
}

int main()
{
	cin >> n >> s;
	memset(dp, -1, sizeof(dp));
	long long ans = solve(0, n-1);
	if (ans >= MOD)
		printf("%05lld\n", ans % MOD);
	else
		printf("%lld\n", ans);

	return 0;
}
