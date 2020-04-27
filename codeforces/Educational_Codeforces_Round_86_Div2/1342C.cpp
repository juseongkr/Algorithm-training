#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

int T;
ll a, b, q, l, r;

ll func(ll k, ll g)
{
	ll ret = 0;
	ret += (k / g) * a;
	ret += min(a-1, (k % g)) + 1;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> a >> b >> q;
		if (a < b)
			swap(a, b);
		ll g = lcm(a, b);
		vector<ll> vec;
		while (q--) {
			cin >> l >> r;
			ll num = r-l+1;
			vec.push_back(num - (func(r, g) - func(l-1, g)));
		}

		for (int i=0; i<vec.size(); ++i)
			cout << vec[i] << " ";
		cout << '\n';
	}

	return 0;
}
