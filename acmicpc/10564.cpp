#include <iostream>
#include <cstring>
using namespace std;
#define MAX 5001

int n, m;
int num[11];
bool dp[MAX][MAX];

void solve(int a, int b)
{
	if (a > n)
		return;
	if (dp[a][b])
		return;

	dp[a][b] = true;
	for (int i=0; i<m; ++i)
		solve(a + b + num[i], b + num[i]);
}

int main()
{
	int t;

	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i=0; i<m; ++i)
			cin >> num[i];

		memset(dp, false, sizeof(dp));

		solve(0, 0);

		int ans = -1;
		for (int i=1; i<=n; ++i)
			if (dp[n][i])
				ans = i;

		cout << ans << '\n';
	}

	return 0;
}
