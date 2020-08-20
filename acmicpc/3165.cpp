#include <iostream>
using namespace std;
#define ll long long

ll n;
int k;

int main()
{
	cin >> n >> k;
	n++;

	ll m = 1;
	while (1) {
		ll t = n;
		int cnt = 0;
		while (t) {
			if (t % 10 == 5)
				cnt++;
			t /= 10;
		}

		if (k <= cnt)
			break;
		while ((n / m) % 10 == 5)
			m *= 10;
		n += m;
	}
	cout << n << '\n';

	return 0;
}
