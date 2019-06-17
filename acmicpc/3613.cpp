#include <iostream>
using namespace std;

int main()
{
	bool cpp = false, java = false;
	string s;

	cin >> s;
	if (!('a' <= s[0] && s[0] <= 'z')) {
		cout << "Error!\n";
		return 0;
	}

	for (int i=1; i<s.length(); ++i) {
		if (s[i] == '_') {
			if (s[i-1] == '_' || i == s.length()-1) {
				cout << "Error!\n";
				return 0;
			}
			cpp = true;
		}
		if ('A' <= s[i] && s[i] <= 'Z')
			java = true;
	}

	if (java && cpp) {
		cout << "Error!\n";
		return 0;
	}

	if (java) {
		for (int i=0; i<s.length(); ++i) {
			if ('A' <= s[i] && s[i] <= 'Z')
				cout << '_' << char(s[i]+32);
			else
				cout << s[i];
		}
	} else if (!cpp) {
		cout << s;
	} else {
		for (int i=0; i<s.length(); ++i) {
			if (s[i] == '_')
				cout << char(s[++i]-32);
			else
				cout << s[i];
		}
	}

	return 0;
}
