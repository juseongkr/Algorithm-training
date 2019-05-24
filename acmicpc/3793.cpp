#include <iostream>
using namespace std;

int dp[201][201];

int main()
{
	string a, b;

	while (cin >> a >> b) {
		for (int i=0; i<201; ++i)
			for (int j=0; j<201; ++j)
				dp[i][j] = 0;

		for (int i=1; i<=a.length(); ++i) {
			for (int j=1; j<=b.length(); ++j) {
				if (a[i-1] == b[j-1])
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}

		cout << dp[a.length()][b.length()] << '\n';
	}

	return 0;
}
