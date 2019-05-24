#include <iostream>
#include <algorithm>
using namespace std;

int dp[5001][5001];

int main()
{
	string s, r;
	int n;

	cin >> n >> s;
	r = s;
	reverse(r.begin(), r.end());
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			if (s[i-1] == r[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	cout << n - dp[n][n] << '\n';

	return 0;
}
