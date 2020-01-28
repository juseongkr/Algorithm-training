#include <iostream>
#include <bitset>
using namespace std;
#define ll long long

ll n, k, y, p = 1;

int main()
{
	cin >> n >> k;
	bitset<64> x(n);
	for (int i=0; i<64; ++i) {
		if (!x[i]) {
			if (k % 2)
				y += p;
			k /= 2;
		}
		p *= 2;
	}
	cout << y << '\n';

	return 0;
}
