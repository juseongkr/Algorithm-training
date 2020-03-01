#include <iostream>
using namespace std;
#define MAX 300003
#define ll long long

ll n, ans;
ll num[MAX], p[MAX], dp[(1 << 21)][2];

int main()
{
	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> num[i];
		p[i] = p[i-1] ^ num[i];
	}

	dp[0][0] = 1;
	for (int i=1; i<=n; ++i) {
		ans += dp[p[i]][i%2];
		dp[p[i]][i%2]++;
	}
	cout << ans << '\n';

	return 0;
}
