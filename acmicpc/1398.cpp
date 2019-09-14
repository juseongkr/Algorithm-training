#include <iostream>
using namespace std;
#define MAX 101
const int INF = 1e9+7;

int coin[3] = {1, 10, 25};
int dp[MAX];

int main()
{
	int t;

	for (int i=1; i<MAX; ++i) {
		dp[i] = INF;
		for (int j=0; j<3; ++j) {
			if (i - coin[j] >= 0)
				dp[i] = min(dp[i], dp[i-coin[j]] + 1);
		}
	}

	cin >> t;
	while (t--) {
		long long n, ans = 0;

		cin >> n;
		while (n) {
			int t = n % 100;
			ans += dp[t];
			n /= 100;
		}
		cout << ans << '\n';
	}

	return 0;
}
