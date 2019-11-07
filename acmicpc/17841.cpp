#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100001
const int MOD = 1e9+7;

int n;
int dp[MAX][6];
string s[MAX];
string u = "UNIST";

int solve(int cur, int len)
{
	if (len == 5)
		return 1;

	if (cur == n)
		return 0;

	if (dp[cur][len] != -1)
		return dp[cur][len];

	dp[cur][len] = solve(cur+1, len);
	for (int i=0; i<s[cur].length(); ++i) {
		if (s[cur][i] != u[len+i])
			break;
		dp[cur][len] += solve(cur+1, len+i+1);
		dp[cur][len] %= MOD;
	}

	return dp[cur][len];
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> s[i];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';

	return 0;
}
