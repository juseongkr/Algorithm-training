#include <iostream>
using namespace std;

int cnt;
string s, ans;

int main()
{
	cin >> s;
	s += '.';
	for (int i=0; i<s.length(); ++i) {
		if (s[i] == 'X') {
			cnt++;
		} else {
			if (cnt & 1) {
				cout << "-1\n";
				return 0;
			}

			for (int i=0; i<cnt/4; ++i)
				ans += "AAAA";
			cnt %= 4;
			for (int i=0; i<cnt/2; ++i)
				ans += "BB";

			cnt = 0;
			ans += '.';
		}
	}
	ans.pop_back();

	cout << ans << '\n';

	return 0;
}
