#include <iostream>
using namespace std;
#define MAX 100
#define ll long long

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, l;

	cin >> n >> l;
	for (ll i=l; i<=MAX; ++i) {
		ll t = (n/i)-i;
		for (ll j=t; j<=n; ++j) {
			ll p = j+1-i;
			if (p >= 0) {
				ll v = j*(j+1)/2 - p*(p-1)/2;
				if (v > n) {
					break;
				} else if (v == n) {
					for (ll k=p; k<=j; ++k)
						cout << k << " ";
					return 0;
				}
			}
		}
	}
	
	cout << "-1\n";

	return 0;
}
