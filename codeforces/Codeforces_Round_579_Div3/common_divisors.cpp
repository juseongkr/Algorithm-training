#include <iostream>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll n, k, g;

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> k;
		g = gcd(g, k);
	}

	ll ans = 0;
	for (ll i=1; i*i<=g; ++i) {
		if (g % i == 0) {
			ans += 2;
			if (i*i == g)
				ans--;
		}
	}
	cout << ans << '\n';

	return 0;
}
