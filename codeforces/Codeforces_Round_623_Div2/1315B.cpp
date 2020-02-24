#include <iostream>
#include <algorithm>
using namespace std;

string s;
int T, a, b, x;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> a >> b >> x >> s;

		int ans = s.length();
		for (int i=s.length()-2; i>=0; i--) {
			if (s[i] == 'A' && x < a)
				break;
			if (s[i] == 'B' && x < b)
				break;

			if (i != 0 && s[i] != s[i-1]) {
				ans = i+1;
				if (s[i] == 'A')
					x -= a;
				if (s[i] == 'B')
					x -= b;
			}
			if (i == 0)
				ans = 1;
		}
		cout << ans << '\n';
	}

	return 0;
}
