#include <iostream>
using namespace std;
#define MAX 1000001

int fail[MAX];

int main()
{
	string s, t;
	int n, m, ans = 0;

	cin >> n >> m >> s;
	for (int i=0; i<n; ++i)
		t += "IO";
	t += 'I';

	for (int i=1, j=0; i<t.length(); ++i) {
		while (j && t[i] != t[j])
			j = fail[j-1];

		if (t[i] == t[j])
			fail[i] = ++j;
	}

	for (int i=0, j=0; i<s.length(); ++i) {
		while (j && s[i] != t[j])
			j = fail[j-1];

		if (s[i] == t[j]) {
			if (j == t.length()-1) {
				ans++;
				j = fail[j];
			} else {
				j++;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
