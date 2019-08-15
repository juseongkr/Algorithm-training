#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 20

int n;
double num[MAX][MAX];
double dp[1<<MAX];

double solve(int cur, int bit)
{
	if (cur == n)
		return 1.0;

	if (dp[bit] != 0.0)
		return dp[bit];

	for (int i=0; i<n; ++i)
		if ((bit & (1 << i)) == 0)
			dp[bit] = max(dp[bit], solve(cur+1, bit | (1 << i)) * num[cur][i]);

	return dp[bit];
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> num[i][j];
			num[i][j] /= 100.0;
		}
	}
	cout << fixed << setprecision(10) << solve(0, 0) * 100.0 << '\n';

	return 0;
}
