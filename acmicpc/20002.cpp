#include <iostream>
using namespace std;
#define MAX 302
const int INF = 1e4+7;

int n, val, sum[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	int ans = -INF;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> val;
			sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + val;
			ans = max(ans, val);
		}
	}
	
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			for (int k=1; k<n; ++k)
				if (i+k <= n && j+k <= n)
				ans = max(ans, sum[i+k][j+k] + sum[i-1][j-1] - sum[i-1][j+k] - sum[i+k][j-1]);

	cout << ans << '\n';

	return 0;
}
