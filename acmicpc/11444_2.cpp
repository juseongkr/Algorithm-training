#include <iostream>
#include <map>
using namespace std;
#define ll long long
#define MOD 1000000007

map<ll, ll> m;

ll fibo(ll n)
{
	if (n == 0) {
		return 0;
	} else if (n == 1 || n == 2) {
		return 1;
	} else if (m.count(n)) {
		return m[n];
	} else if (n % 2 == 0) {
		ll t = n / 2;
		ll x = fibo(t);
		ll y = fibo(t-1);
		m[n] = x * (x + 2 * y);
		return m[n] %= MOD;
	} else {
		ll t = (n+1) / 2;
		ll x = fibo(t);
		ll y = fibo(t-1);
		m[n] = x*x + y*y;
		return m[n] %= MOD;
	}
}

int main()
{
	ll n;
	cin >> n;

	cout << fibo(n) << '\n';

	return 0;
}
