#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 1000001

int n;
double dp[MAX];

double solve(int k)
{
	if (k == 0)
		return 0;

	if (dp[k] != -1)
		return dp[k];

	dp[k] = 0;
	for (int i=1; i<=6; ++i) {
		if (k-i >= 0)
			dp[k] += solve(k-i) + 1;
		else
			dp[k] += 1;
	}

	return dp[k] /= 6;
}

int main()
{
	cin >> n;

	fill(dp, dp+MAX, -1);
	cout << fixed << setprecision(10) << solve(n) << '\n';

	return 0;
}
