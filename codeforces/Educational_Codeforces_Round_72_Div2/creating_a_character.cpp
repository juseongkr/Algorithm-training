#include <iostream>
using namespace std;

int main()
{
	int t, S, I, E;

	cin >> t;
	while (t--) {
		cin >> S >> I >> E;
		int l = 0, r = E;
		while (l <= r) {
			int mid = (l+r)/2;
			if (S + mid > I + (E-mid))
				r = mid - 1;
			else
				l = mid + 1;
		}
		cout << E - r << '\n';
	}

	return 0;
}
