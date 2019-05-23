#include <iostream>
#include <algorithm>
using namespace std;

int dict[26];

int main()
{
	int flag = 0, center = -1;
	string s;

	cin >> s;
	for (int i=0; i<s.length(); ++i)
		dict[s[i]-'A']++;

	for (int i=0; i<26; ++i) {
		if (dict[i] % 2 == 1) {
			center = i;
			dict[i]--;
			flag++;
		}
	}

	if (flag >= 2) {
		cout << "I'm Sorry Hansoo\n";
	} else {
		string ans, ret;
		for (int i=0; i<26; ++i) {
			if (dict[i])
				for (int j=0; j<dict[i]/2; ++j)
					ans += (i+'A');
		}
		ret = ans;
		reverse(ret.begin(), ret.end());
		if (center != -1)
			ans += (center+'A');
		ans += ret;

		cout << ans << '\n';
	}

	return 0;
}
