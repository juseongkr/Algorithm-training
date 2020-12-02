#include <iostream>
using namespace std;
#define MAX 31

int n, k;
int dp[MAX][MAX][MAX][436];
char ans[MAX];

int solve(int i, int a, int b, int p)
{
	if (i == n) {
		if (p == k)
			return true;
		return false;
	}

	if (dp[i][a][b][p])
		return false;

	dp[i][a][b][p] = true;
	ans[i] = 'A';
	if (solve(i+1, a+1, b, p))
		return true;

	ans[i] = 'B';
	if (solve(i+1, a, b+1, p+a))
		return true;

	ans[i] = 'C';
	if (solve(i+1, a, b, p+a+b))
		return true;

	return false;
}

int main()
{
	cin >> n >> k;
	if (solve(0, 0, 0, 0))
		cout << ans << '\n';
	else
		cout << "-1\n";

	return 0;
}
