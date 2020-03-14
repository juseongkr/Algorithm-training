#include <iostream>
using namespace std;
#define ll long long

ll u, v;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> u >> v;
	ll k = abs(u-v);
	if (u > v || k % 2) {
		cout << "-1\n";
		return 0;
	}

	if (v == 0) {
		cout << "0\n";
		return 0;
	}

	if (k == 0) {
		cout << "1 \n" << u << '\n';
		return 0;
	}

	if (u + k/2 == (u ^ (k/2))) {
		cout << "2\n" << u + k/2 << " " << k/2 << '\n';
	} else {
		cout << "3\n" << u << " " << k/2 << " " << k/2 << '\n';
	}

	return 0;
}
