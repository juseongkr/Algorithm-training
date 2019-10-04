#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 61

int n;
int num[3];
int dp[MAX][MAX][MAX];

int solve(int a, int b, int c)
{
	if (a == 0 && b == 0 && c == 0)
		return 0;
	if (a < 0)
		return solve(0, b, c);
	if (b < 0)
		return solve(a, 0, c);
	if (c < 0)
		return solve(a, b, 0);
	
	if (dp[a][b][c] != -1)
		return dp[a][b][c];

	vector<int> v = {1, 3, 9};
	dp[a][b][c] = 1e9+7;
	do {
		dp[a][b][c] = min(dp[a][b][c], solve(a-v[0], b-v[1], c-v[2]) + 1);
	} while (next_permutation(v.begin(), v.end()));

	return dp[a][b][c];
}

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<n; ++i)
		cin >> num[i];

	cout << solve(num[0], num[1], num[2]) << '\n';

	return 0;
}
