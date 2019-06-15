#include <iostream>
using namespace std;
#define ll long long
#define MAX 1000001

bool check[MAX];

int main()
{
	ll a, b;
	
	cin >> a >> b;
	fill(check, check+MAX, true);
	for (ll i=2; i*i<=b; ++i) {
		ll x = a / (i*i);
		if ((i*i)*x != a)
			x++;
		for (ll j=x; j*(i*i)<=b; ++j)
			check[j*(i*i)-a] = false;
	}

	int ans = 0;
	for (int i=0; i<=b-a; ++i)
		if (check[i])
			ans++;

	cout << ans << '\n';

	return 0;
}
