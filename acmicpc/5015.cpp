#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101

int n;
string p, s;
int dp[MAX][MAX];

int solve(int i, int j)
{
	if (i >= p.length() && j == s.length())
		return 1;

	if (dp[i][j] != -1)
		return dp[i][j];

	dp[i][j] = 0;
	if (p[i] == '*')
		dp[i][j] |= (solve(i+1, j) || solve(i, j+1));
	else if (p[i] == s[j])
		dp[i][j] |= solve(i+1, j+1);

	return dp[i][j];
}

int main()
{
	cin >> p >> n;
	for (int i=0; i<n; ++i) {
		cin >> s;
		memset(dp, -1, sizeof(dp));
		if (solve(0, 0))
			cout << s << '\n';
	}

	return 0;
}
