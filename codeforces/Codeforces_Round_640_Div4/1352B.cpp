#include <iostream>
using namespace std;

int T, n, k;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> k;

		int a = n - (k-1);
		int b = n - (k-1) * 2;

		if (a > 0 && a % 2 == 1) {
			cout << "YES\n";
			for (int i=0; i<k-1; ++i)
				cout << "1 ";
			cout << a << '\n';
		} else if (b > 0 && b % 2 == 0) {
			cout << "YES\n";
			for (int i=0; i<k-1; ++i)
				cout << "2 ";
			cout << b << '\n';
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}
