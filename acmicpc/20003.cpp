#include <iostream>
using namespace std;
#define MAX 51
#define ll long long

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

ll n, a, b, x, y = 1;

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a >> b;
		ll t = gcd(a, b);
		y = lcm(y, b/t);
		if (i == 0)
			x = a/t;
		else
			x = gcd(x, a/t);
	}
	cout << x << " " << y << '\n';

	return 0;
}
