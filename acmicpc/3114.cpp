#include <iostream>
using namespace std;
#define MAX 1501

int a[MAX][MAX], b[MAX][MAX], dp[MAX][MAX];

int main()
{
	string s;
	int n, m;

	cin >> n >> m;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			cin >> s;
			string t;
			for (int k=1; k<s.length(); ++k)
				t += s[k];
			int val = atoi(t.c_str());
			if (s[0] == 'A')
				a[i][j] += val;
			else
				b[i][j] += val;
		}
	}

	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j)
			a[i][j] += a[i][j-1];

	for (int i=1; i<=n; ++i)
		for (int j=m-1; j>0; j--)
			b[i][j] += b[i][j+1];

	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			if (i == 1 || j == 1) {
				dp[i][j] = dp[i-1][j] + b[i][j+1];
			} else {
				dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + a[i][j-1] + b[i][j+1];
				dp[i][j] = max(dp[i][j], dp[i][j-1] - b[i][j] + b[i][j+1]);
			}
		}
	}
	cout << dp[n][m] << '\n';

	return 0;
}
