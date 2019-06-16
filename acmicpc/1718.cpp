#include <iostream>
using namespace std;

int main()
{
	string s, r;

	getline(cin, s);
	cin >> r;
	int len = r.length();
	for (int i=0; i<s.length(); ++i) {
		if (s[i] == ' ') {
			cout << ' ';
		} else {
			int t = s[i] - (r[i%len]-96);
			if (t < 97)
				t += 26;
			cout << char(t);
		}
	}
	return 0;
}
