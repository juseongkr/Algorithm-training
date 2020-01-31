#include <iostream>
using namespace std;

int t, n;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;

		string s;
		if (n % 2) {
			s += '7';
			n -= 3;
			for (int i=0; i<n/2; ++i)
				s += '1';
		} else {
			for (int i=0; i<n/2; ++i)
				s += '1';
		}
		cout << s << '\n';
	}

	return 0;
}
