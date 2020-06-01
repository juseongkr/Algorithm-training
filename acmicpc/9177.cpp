#include <iostream>
#include <cstring>
using namespace std;
#define MAX 201

int t;
string a, b, c;
int dp[MAX][MAX];

int solve(int i, int j)
{
	if (i >= a.length() && j >= b.length())
		return 1;

	if (dp[i][j] != -1)
		return dp[i][j];

	dp[i][j] = 0;
	if (i < a.length() && a[i] == c[i+j])
		dp[i][j] |= solve(i+1, j);

	if (j < b.length() && b[j] == c[i+j])
		dp[i][j] |= solve(i, j+1);

	return dp[i][j];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> t;
	for (int i=1; i<=t; ++i) {
		cin >> a >> b >> c;
		memset(dp, -1, sizeof(dp));
		int ans = solve(0, 0);
		if (ans)
			cout << "Data set " << i << ": yes\n";
		else
			cout << "Data set " << i << ": no\n";
	}

	return 0;
}
