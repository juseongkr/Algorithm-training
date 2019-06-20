#include <iostream>
using namespace std;

int main()
{
	int dict[26];

	while (1) {
		string s;
		getline(cin, s);
		fill(dict, dict+26, 0);
		if (s == "#")
			break;

		for (int i=0; i<s.length(); ++i) {
			if ('a' <= s[i] && s[i] <= 'z')
				dict[s[i]-'a'] = 1;
			else if ('A' <= s[i] && s[i] <= 'Z')
				dict[s[i]-'A'] = 1;
		}
		
		int ans = 0;
		for (int i=0; i<26; ++i)
			if (dict[i])
				ans++;

		cout << ans << '\n';
	}

	return 0;
}
