#include <iostream>
using namespace std;

int main()
{
	int dict[26];
	string s;
	int n, flag;

	cin >> n;
	while (n--) {
		cin >> s;
		fill(dict, dict+26, 0);
		flag = 0;
		for (int i=0; i<s.length(); ++i) {
			dict[s[i]-'A']++;
			if (dict[s[i]-'A'] == 3) {
				if ((s[i] != s[i+1] && i+1 < s.length()) ||
			       	   (i+1 >= s.length())) {
					flag = 1;
					break;
				} else if (s[i] == s[i+1] && i+1 < s.length()) {
					dict[s[i]-'A'] = -1;
				}
			}
		}
		if (flag)
			cout << "FAKE\n";
		else
			cout << "OK\n";
	}
	return 0;
}
