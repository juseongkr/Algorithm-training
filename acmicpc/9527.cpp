#include <iostream>
using namespace std;
#define ll long long

ll sum(ll n)
{
	ll ret = 0, k = 1;
	for (ll t=n+1; t>0; t/=2, k*=2) {
		if ((n / k) % 2 != 0)
			ret += (n - (n % (2 * k))) / 2 + n % k;
		else
			ret += (n - (n % k)) / 2;
	}
	return ret;
}

int main()
{
	ll a, b;

	cin >> a >> b;

	cout << sum(b+1) - sum(a) << '\n';

	return 0;
}
