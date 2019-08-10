#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001

int n;
int num[MAX];
int dp[MAX][MAX];

int solve(int a, int b)
{
	if (a > b)
		return 0;

	if (dp[a][b] != -1)
		return dp[a][b];

	dp[a][b] = solve(a+1, b);
	for (int i=a+1; i<=b; ++i)
		if (num[a] == num[i])
			dp[a][b] = max(dp[a][b], solve(a+1, i-1) + solve(i+1, b) + 1);
	return dp[a][b];
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, n-1) << '\n';

	return 0;
}
