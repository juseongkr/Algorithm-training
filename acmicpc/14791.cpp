#include <iostream>
using namespace std;
#define ll long long
const ll INF = 1e18;

int t;
ll n;

int main()
{
	cin >> t;
	for (int T=1; T<=t; ++T) {
		cin >> n;

		ll ans = 0, k = INF;
		while (k > 1) {
			ll i = 0;
			for (i=9; i>0; i--)
				if (ans + (k / 9 * i) <= n)
					break;
			k /= 10;
			ans += k * i;
		}
		cout << "Case #" << T << ": " << ans << '\n';
	}

	return 0;
}
