#include <iostream>
using namespace std;

int main()
{
	int q;
	string s;

	cin >> q;
	while (q--) {
		cin >> s;

		int U = 0, D = 0, L = 0, R = 0;
		int n = s.length();
		for (int i=0; i<n; ++i) {
			if (s[i] == 'U')
				U++;
			else if (s[i] == 'D')
				D++;
			else if (s[i] == 'L')
				L++;
			else
				R++;
		}

		int x = min(L, R);
		int y = min(U, D);

		if (x == 0 || y == 0) {
			x = min(x, 1);
			y = min(y, 1);
		}

		string ans;
		cout << x*2 + y*2 << '\n';
		for (int i=0; i<x; ++i)
			ans += "R";
		for (int i=0; i<y; ++i)
			ans += "U";
		for (int i=0; i<x; ++i)
			ans += "L";
		for (int i=0; i<y; ++i)
			ans += "D";
		cout << ans << '\n';
	}

	return 0;
}
