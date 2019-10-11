#include <iostream>
using namespace std;

int main()
{
	string s;
	int t;

	cin >> t;
	while (t--) {
		cin >> s;
		int cnt = 0, ans = 0;
		for (int i=0; i<s.length(); ++i) {
			if (s[i] == '0') {
				cnt++;
			} else {
				int k = 0;
				for (int j=i; j<s.length(); ++j) {
					k = k * 2 + (s[j]-'0');
					if (j - i + 1 + cnt < k)
						break;
					ans++;
				}
				cnt = 0;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
