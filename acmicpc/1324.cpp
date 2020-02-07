#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001

int n;
int a[MAX], b[MAX];
int dp[MAX][MAX];

int solve(int x, int y)
{
	if (x == n || y == n)
		return 0;

	if (~dp[x][y])
		return dp[x][y];

	dp[x][y] = 1;
	for (int i=x+1; i<n; ++i) {
		if (a[x] < a[i]) {
			for (int j=y+1; j<n; ++j) {
				if (a[i] == b[j]) {
					dp[x][y] = max(dp[x][y], solve(i, j) + 1);
					break;
				}
			}
		}
	}

	return dp[x][y];
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];

	for (int i=0; i<n; ++i)
		cin >> b[i];

	int ans = 0;
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (a[i] == b[j]) {
				ans = max(ans, solve(i, j));
				break;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
