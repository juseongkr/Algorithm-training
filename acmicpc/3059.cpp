#include <iostream>
using namespace std;

int main()
{
	int dict[26];
	string s;
	int t;

	cin >> t;
	while (t--) {
		cin >> s;
		fill(dict, dict+26, 0);
		for (int i=0; i<s.length(); ++i)
			dict[s[i]-'A']++;

		int ans = 0;
		for (int i=0; i<26; ++i)
			if (!dict[i])
				ans += i+'A';

		cout << ans << '\n';
	}

	return 0;
}
