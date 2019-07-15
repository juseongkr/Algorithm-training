#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101

string n, s[2];
int dp[21][2][MAX];

int solve(int cur, int col, int row)
{
	if (cur == n.length())
		return 1;

	if (dp[cur][col][row] != -1)
		return dp[cur][col][row];

	dp[cur][col][row] = 0;
	for (int i=row; i<s[0].length(); ++i)
		if (n[cur] == s[col][i])
			dp[cur][col][row] += solve(cur+1, 1-col, i+1);

	return dp[cur][col][row];
}

int main()
{
	cin >> n >> s[0] >> s[1];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 1, 0) + solve(0, 0, 0) << '\n';

	return 0;
}
