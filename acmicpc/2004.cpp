#include <iostream>
using namespace std;
#define ll long long

int main()
{
	ll a = 0, b = 0;
	int n, m;

	cin >> n >> m;
	for (ll i=5; i<=n; i*=5)
		a += n/i;

	for (ll i=5; i<=n-m; i*=5)
		a -= (n-m)/i;

	for (ll i=5; i<=m; i*=5)
		a -= m/i;

	for (ll i=2; i<=n; i*=2)
		b += n/i;

	for (ll i=2; i<=n-m; i*=2)
		b -= (n-m)/i;

	for (ll i=2; i<=m; i*=2)
		b -= m/i;

	cout << min(a, b) << '\n';

	return 0;
}
