#include <iostream>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;

ll n, m;

ll pow(ll a, ll b)
{
	ll ret = 1;
	while (b) {
		if (b % 2)
			ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b /= 2;
	}
	return ret;
}

int main()
{
	cin >> n >> m;

	cout << pow(pow(2, m)-1, n) << '\n';

	return 0;
}
