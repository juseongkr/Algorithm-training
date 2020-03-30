#include <iostream>
using namespace std;

int T, n;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		string x, a, b;
		cin >> n >> x;
		a += '1';
		b += '1';
		int i;
		for (i=1; i<n; ++i) {
			if (x[i] == '1') {
				a += '1';
				b += '0';
				break;
			} else if (x[i] == '0') {
				a += '0';
				b += '0';
			} else {
				a += '1';
				b += '1';
			}
		}

		for (int j=i+1; j<n; ++j) {
			if (x[j] == '1') {
				a += '0';
				b += '1';
			} else if (x[j] == '0') {
				a += '0';
				b += '0';
			} else {
				a += '0';
				b += '2';
			}
		}
		cout << a << '\n' << b << '\n';
	}

	return 0;
}
