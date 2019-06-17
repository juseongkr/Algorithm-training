#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<string> dict;
	string s;

	while (1) {
		bool flag = true;
		cin >> s;
		if (s == "*")
			break;
		for (int i=1; i<s.length(); ++i) {
			for (int j=0; j<s.length()-i; ++j) {
				string t;
				t += s[j];
				t += s[j+i];
				if (dict.count(t)) {
					cout << s << " is NOT surprising.\n";
					flag = false;
					break;
				} else {
					dict.insert(t);
				}
			}
			dict.clear();
			if (!flag)
				break;
		}
		if (flag)
			cout << s << " is surprising.\n";
	}

	return 0;
}
