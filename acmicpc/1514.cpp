#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101

int n;
int dp[MAX][10][10];
int a[MAX], b[MAX];
int turn[10] = {0, 1, 1, 1, 2, 2, 2, 1, 1, 1};

int solve(int i, int j, int k)
{
	if (i == n)
		return 0;

	if (dp[i][j][k] != -1)
		return dp[i][j][k];

	dp[i][j][k] = 1e9+7;
	for (int th=0; th<10; ++th) {
		for (int se=0; se<10; ++se) {
			int fi = b[i] - ((a[i] + j) % 10 + se + th) % 10;
			if (fi < 0)
				fi += 10;
			int cost = turn[fi] + turn[se] + turn[th];
			cost += solve(i+1, (se + th + k) % 10, th);
			dp[i][j][k] = min(dp[i][j][k], cost);
		}
	}

	return dp[i][j][k];
}

int main()
{
	string s1, s2;
	cin >> n >> s1 >> s2;
	for (int i=0; i<n; ++i) {
		a[i] = s1[i]-'0';
		b[i] = s2[i]-'0';
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0, 0) << '\n';

	return 0;
}
