#include <iostream>
using namespace std;
#define MAX 101

int T;
string s;

int main()
{
	cin >> T;
	for (int t=1; t<=T; ++t) {
		cin >> s;
		string p;
		int cnt = 0;
		if (s[0] == '0') {
			p += '0';
		} else {
			for (int i=0; i<s[0]-'0'; ++i) {
				p += '(';
				cnt++;
			}
			p += s[0];
		}

		for (int i=1; i<s.length(); ++i) {
			if (s[i-1] == s[i]) {
				p += s[i];
			} else if (s[i-1] > s[i]) {
				for (int j=(s[i]-'0'); j<cnt; ++j)
					p += ')';
				cnt = (s[i]-'0');
				p += s[i];
			} else {
				for (int j=cnt; j<s[i]-'0'; ++j)
					p += '(';
				cnt = (s[i]-'0');
				p += s[i];
			}
		}

		for (int i=0; i<cnt; ++i)
			p += ')';

		cout << "Case #" << t << ": " << p << '\n';
	}

	return 0;
}
