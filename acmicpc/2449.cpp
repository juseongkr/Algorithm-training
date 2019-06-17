#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
#define MAX 201

int n, k;
int num[MAX], dp[MAX][MAX];

int solve(int a, int b)
{
	if (a == b)
		return 0;

	if (dp[a][b] != -1)
		return dp[a][b];

	dp[a][b] = INT_MAX;
	for (int i=a; i<b; ++i) {
		int add = 0;
		if (num[a] != num[i+1])
			add = 1;
		dp[a][b] = min(dp[a][b], solve(a, i) + solve(i+1, b) + add);
	}
	return dp[a][b];
}

int main()
{
	cin >> n >> k;

	memset(dp, -1, sizeof(dp));
	for (int i=1; i<=n; ++i)
		cin >> num[i];

	cout << solve(1, n) << '\n';

	return 0;
}
