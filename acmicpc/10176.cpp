#include <iostream>
using namespace std;

int main()
{
	string s;
	int t;

	cin >> t;
	while (t--) {
		cin >> s;
		bool flag = false;
		for (int i=0; i<s.length(); ++i) {
			if ('A' <= s[i] && s[i] <= 'Z')
				s[i] += 32;
		}
		for (int i=0; i<s.length(); ++i) {
			char a = s[i];
			char b = s[s.length()-i-1];

			if (abs(a-b) != abs(b-a))
				flag = true;
		}
		if (flag)
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}
