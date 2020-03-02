#include <iostream>
#include <vector>
using namespace std;
#define MAX 5001
const int INF = 1e9+7;

int t, n;
int dp[MAX][MAX], knuth[MAX][MAX];

int main()
{
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> num(n+1, 0), sum(n+1, 0);
		for (int i=1; i<=n; ++i) {
			cin >> num[i];
			sum[i] = sum[i-1] + num[i];
		}

		for (int i=1; i<=n; ++i) {
			dp[i-1][i] = 0;
			knuth[i-1][i] = i; 
		}

		for (int m=2; m<=n; ++m) {
			for (int i=0; i<=n-m; ++i) {
				int j = i+m;
				dp[i][j] = INF;
				for (int k=knuth[i][j-1]; k<=knuth[i+1][j]; ++k) {
					int cur = dp[i][k] + dp[k][j] + sum[j] - sum[i];
					if (dp[i][j] > cur) {
						dp[i][j] = cur;
						knuth[i][j] = k;
					}
				}
			}
		}
		cout << dp[0][n] << '\n';
	}

	return 0;
}
