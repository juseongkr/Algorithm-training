#include <iostream>
using namespace std;

#define ll long long
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }                                                         

int main()
{
	int num[101];
	int t, n;

	cin >> t;
	while (t--) {
		cin >> n;

		ll ans = 0;
		for (int i=0; i<n; ++i)
			cin >> num[i];

		for (int i=0; i<n; ++i)
			for (int j=i+1; j<n; ++j)
				ans += gcd(num[i], num[j]);

		cout << ans << '\n';

	}

	return 0;
}
