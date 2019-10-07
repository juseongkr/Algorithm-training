#include <iostream>
using namespace std;
#define MAX 100001

int num[MAX], dp[MAX], candy[MAX], t[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, m;

	while (1) {
		fill(num, num+MAX, 0);
		fill(dp, dp+MAX, 0);
		fill(candy, candy+MAX, 0);
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		for (int i=1; i<=n; ++i) {
			for (int j=1; j<=m; ++j)
				cin >> t[j];
			num[1] = t[1];
			for (int j=2; j<=m; ++j)
				num[j] = max(num[j-1], num[j-2] + t[j]);
			candy[i] = num[m];
		}

		dp[1] = candy[1];
		for (int i=2; i<=n; ++i)
			dp[i] = max(dp[i-1], dp[i-2] + candy[i]);

		cout << dp[n] << '\n';
	}
	
	return 0;
}
