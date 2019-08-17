#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s, p;
	int n;
	
	cin >> n >> s;
	for (int i=0; i<10; ++i)
		p += '0';

	int l = 0, r = 9;
	for (int i=0; i<n; ++i) {
		if (s[i] == 'L') {
			for (int i=0; i<10; ++i) {
				if (p[i] == '0') {
					p[i] = '1';
					break;
				}
			}

		} else if (s[i] == 'R') {
			for (int i=9; i>=0; i--) {
				if (p[i] == '0') {
					p[i] = '1';
					break;
				}
			}

		} else {
			p[s[i]-'0'] = '0';
		}
	}
	cout << p << '\n';

	return 0;
}
