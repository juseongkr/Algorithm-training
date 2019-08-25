#include <iostream>
#include <vector>
using namespace std;
#define MAX 401

int dp[MAX][MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> a, b;
	int n, t;

	cin >> n;
	a.push_back(0);
	b.push_back(0);
	for (int i=0; i<n; ++i) {
		cin >> t;
		if (t != 0)
			a.push_back(t);
	}

	for (int i=0; i<n; ++i) {
		cin >> t;
		if (t != 0)
			b.push_back(t);
	}

	for (int k=1; k<=n; ++k) {
		for (int i=1; i<a.size(); ++i) {
			for (int j=1; j<b.size(); ++j) {
				if (i > k || j > k)
					continue;

				int cur = dp[k-1][i-1][j-1] + a[i] * b[j];
				if (j-1 >= 0 && k-1 >= i)
					cur = max(cur, dp[k-1][i][j-1]);

				if (i-1 >= 0 && k-1 >= j)
					cur = max(cur, dp[k-1][i-1][j]);

				dp[k][i][j] = cur;
			}
		}
	}
	cout << dp[n][a.size()-1][b.size()-1] << '\n';

	return 0;
}
