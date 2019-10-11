#include <iostream>
using namespace std;
#define MAX 101

int main()
{
	int t, n, x, a, b;

	cin >> t;
	while (t--) {
		cin >> n >> x;
		int d = 0, h = 0;
		for (int i=0; i<n; ++i) {
			cin >> a >> b;
			d = max(d, a);
			h = max(h, a-b);
		}
		if (d >= x) {
			cout << "1\n";
		} else {
			if (h == 0) {
				cout << "-1\n";
			} else {
				x -= d;
				cout << (x+h-1)/h+1 << '\n';
			}
		}
	}

	return 0;
}
