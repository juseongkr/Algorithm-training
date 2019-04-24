#include <iostream>
using namespace std;

int dp[1001][1001];

int main()
{	
	string s1, s2;

	cin >> s1 >> s2;
	for (int i=1; i<=s1.length(); ++i) {
		for (int j=1; j<=s2.length(); ++j) {
			if (s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	cout << dp[s1.length()][s2.length()] << '\n';

	return 0;
}
