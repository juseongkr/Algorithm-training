#include <iostream>
#include <cstring>
using namespace std;
#define MAX 501

int n;
string s;
int dp[MAX][MAX];

int solve(int l, int r)
{
	if (l >= r)
		return 0;

	if (dp[l][r] != -1)
		return dp[l][r];

	dp[l][r] = solve(l+1, r);
	if (s[l] == 'a') {
		for (int i=l+1; i<r; ++i) {
			if (s[i] == 't')
				dp[l][r] = max(dp[l][r], solve(l+1, i) + solve(i+1, r) + 2);
		}
	}

	if (s[l] == 'g') {
		for (int i=l+1; i<r; ++i) {
			if (s[i] == 'c')
				dp[l][r] = max(dp[l][r], solve(l+1, i) + solve(i+1, r) + 2);

		}
	}

	return dp[l][r];
}

int main()
{
	cin >> s;
	n = s.length();
	
	memset(dp, -1, sizeof(dp));
	cout << solve(0, n) << '\n';

	return 0;
}
