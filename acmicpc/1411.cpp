#include <iostream>
using namespace std;

int main()
{
	int a[26], b[26];
	string s[101];
	int n;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> s[i];

	int ans = 0;
	for (int i=0; i<n; ++i) {
		for (int j=i+1; j<n; ++j) {
			fill(a, a+26, 0);
			fill(b, b+26, 0);
			bool flag = true;
			if (s[i].length() != s[j].length()) {
				flag = false;
				break;
			}

			for (int k=0; k<s[i].length(); ++k) {
				if (!a[s[i][k]-'a'] && !b[s[j][k]-'a']) {
					a[s[i][k]-'a'] = s[j][k];
					b[s[j][k]-'a'] = s[i][k];
				}
				if (a[s[i][k]-'a'] != s[j][k] || b[s[j][k]-'a'] != s[i][k]) {
					flag = false;
					break;
				}
			}
			if (flag)
				ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}
