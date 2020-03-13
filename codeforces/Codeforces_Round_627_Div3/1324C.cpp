#include <iostream>
using namespace std;

int T;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> s;
		int ans = 0, cnt = 0;
		for (int i=0; i<s.length(); ++i) {
			if (s[i] == 'R') {
				cnt = 0;
			} else {
				cnt++;
				ans = max(ans, cnt);
			}
		}
		cout << ans+1 << '\n';
	}

	return 0;
}
