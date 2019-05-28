#include <iostream>
using namespace std;
#define MAX 4001

int dp[MAX][MAX];

int main()
{
	int ans = 0;
	string s, r;

	cin >> s >> r;
	for (int i=1; i<=s.length(); ++i) {
		for (int j=1; j<=r.length(); ++j) {
			if (s[i-1] == r[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << '\n';

	return 0;
}
