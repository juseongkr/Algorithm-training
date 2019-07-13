#include <iostream>
#include <cstring>
using namespace std;
#define MAX 2001

int n;
int A[MAX], B[MAX];
int dp[MAX][MAX];

int solve(int l, int r)
{
	if (l == n || r == n)
		return 0;

	if (dp[l][r] != -1)
		return dp[l][r];

	dp[l][r] = 0;
	if (A[l] > B[r]) {
		int a = solve(l, r+1) + B[r];
		int b = solve(l+1, r);
		int c = solve(l+1, r+1);
		dp[l][r] += max(a, max(b, c));
	} else {
		dp[l][r] += max(solve(l+1, r), solve(l+1, r+1));
	}
	return dp[l][r];
}

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<n; ++i)
		cin >> A[i];
	for (int i=0; i<n; ++i)
		cin >> B[i];

	cout << solve(0, 0) << '\n';

	return 0;
}
