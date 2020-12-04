#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001
const int MOD = 1234567;

int T, n;
int dp[10][MAX];
bool check[10][10] = {
{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
{0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
{0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
{0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
{0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
{0, 0, 1, 0, 1, 0, 1, 0, 1, 0},
{0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
{1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
{0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
{0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
};

int solve(int m, int k)
{
	if (k == 1)
		return 1;

	if (~dp[m][k])
		return dp[m][k];

	dp[m][k] = 0;
	for (int i=0; i<10; ++i)
		if (check[m][i])
			dp[m][k] += (solve(i, k-1) % MOD);

	return dp[m][k];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;

		int ans = 0;
		memset(dp, -1, sizeof(dp));
		for (int i=0; i<10; ++i)
			ans = (ans + solve(i, n)) % MOD;

		cout << ans << '\n';
	}

	return 0;
}
