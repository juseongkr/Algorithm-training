#include <iostream>
using namespace std;

int main()
{
	string s;
	int t, n;

	cin >> t;
	while (t--) {
		cin >> n >> s;
		bool flag = false;
		int cnt = 0, ans = 0;
		for (int i=0; i<n; ++i) {
			if (s[i] == 'A') {
				cnt = 0;
				flag = true;
			} else if (flag) {
				cnt++;
				ans = max(ans, cnt);
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
