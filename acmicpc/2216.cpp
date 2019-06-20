#include <iostream>
using namespace std;
#define MAX 3001

int dp[MAX][MAX];

int main()
{
	string s, r;
	int a, b, c;

	cin >> a >> b >> c >> s >> r;
	for (int i=1; i<MAX; ++i)
		dp[i][0] = dp[0][i] = i*b;

	for (int i=1; i<=s.length(); ++i) {
		for (int j=1; j<=r.length(); ++j) {
			if (s[i-1] == r[j-1])
				dp[i][j] = dp[i-1][j-1] + a;
			else
				dp[i][j] = max(dp[i-1][j-1] + max(b * 2, c), max(dp[i][j-1], dp[i-1][j]) + b);
		}
	}

	cout << dp[s.length()][r.length()] << '\n';

	return 0;
}
