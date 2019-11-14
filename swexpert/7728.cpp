#include <iostream>
using namespace std;

int main()
{
	int dict[26];
	string s;
	int t;

	cin >> t;
	for (int i=1; i<=t; ++i) {
		cin >> s;
		fill(dict, dict+26, 0);
		for (int j=0; j<s.length(); ++j)
			dict[s[j]-'0']++;

		int ans = 0;
		for (int j=0; j<26; ++j)
			if (dict[j])
				ans++;

		cout << "#" << i << " " << ans << '\n';
	}

	return 0;
}
