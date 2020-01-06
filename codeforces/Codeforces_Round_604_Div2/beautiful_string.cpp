#include <iostream>
using namespace std;

int main()
{
	string s;
	int t;

	cin >> t;
	while (t--) {
		cin >> s;
		int n = s.length();

		for (int i=0; i<n; ++i) {
			if (s[i] == '?') {
				for (int j='a'; j<='c'; ++j) {
					if (s[i-1] != j && s[i+1] != j) {
						s[i] = j;
						break;
					}
				}
			}
		}
		bool flag = true;
		for (int i=0; i<n-1; ++i) {
			if (s[i] == s[i+1]) {
				flag = false;
				break;
			}
		}
		if (flag)
			cout << s << '\n';
		else
			cout << "-1\n";
	}

	return 0;
}
