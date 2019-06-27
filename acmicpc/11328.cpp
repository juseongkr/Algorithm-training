#include <iostream>
using namespace std;

int main()
{
	int dict[26], dict2[26];
	string a, b;
	int n;

	cin >> n;
	while (n--) {
		cin >> a >> b;
		int flag = false;
		fill(dict, dict+26, 0);
		fill(dict2, dict2+26, 0);
		if (a.length() != b.length())
			flag = true;
		
		for (int i=0; i<a.length(); ++i) {
			dict[a[i]-'a']++;
			dict2[b[i]-'a']++;
		}

		for (int i=0; i<26; ++i) {
			if (dict[i] != dict2[i]) {
				flag = true;
				break;
			}
		}

		if (flag)
			cout << "Impossible\n";
		else
			cout << "Possible\n";
	}

	return 0;
}
