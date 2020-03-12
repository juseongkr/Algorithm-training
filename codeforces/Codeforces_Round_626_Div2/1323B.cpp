#include <iostream>
using namespace std;
#define ll long long
#define MAX 40001

ll n, m, k;
ll a[MAX], b[MAX], pa[MAX], pb[MAX];

int main()
{
	cin >> n >> m >> k;
	for (int i=0; i<n; ++i)
		cin >> a[i];

	for (int i=0; i<m; ++i)
		cin >> b[i];

	int cnt = 0;
	for (int i=0; i<n; ++i) {
		if (a[i]) {
			cnt++;
			pa[cnt]++;
		} else {
			cnt = 0;
		}
	}

	cnt = 0;
	for (int i=0; i<m; ++i) {
		if (b[i]) {
			cnt++;
			pb[cnt]++;
		} else {
			cnt = 0;
		}
	}

	for (int i=n; i>=1; i--)
		pa[i-1] += pa[i];

	for (int i=m; i>=1; i--)
		pb[i-1] += pb[i];

	ll ans = 0;
	for (int i=1; i*i<=k; ++i) {
		if (k % i == 0) {
			if (i <= n && k / i <= m)
				ans += pa[i] * pb[k/i];
			if (k / i > n || i > m || i*i == k)
				continue;
			ans += pa[k/i]  * pb[i];
		}
	}
	cout << ans << '\n';

	return 0;
}
