#include <iostream>
using namespace std;

int main()
{
	int t;

	cin >> t;
	while (t--) {
		char p[101];
		string s;
		int n, a, b, c, cnt = 0;
		fill(p, p+101, 0);

		cin >> n >> a >> b >> c >> s;
		for (int i=0; i<n; ++i) {
			if (s[i] == 'S' && a > 0) {
				cnt++;
				p[i] = 'R';
				a--;
			} else if (s[i] == 'R' && b > 0) {
				cnt++;
				p[i] = 'P';
				b--;
			} else if (s[i] == 'P' && c > 0) {
				cnt++;
				p[i] = 'S';
				c--;
			}
		}

		for (int i=0; i<n; ++i) {
			if (p[i] == 0) {
				if (a > 0) {
					p[i] = 'R';
					a--;
				} else if (b > 0) {
					p[i] = 'P';
					b--;
				} else if (c > 0) {
					p[i] = 'S';
					c--;
				}
			}
		}

		if (cnt >= (n+1)/2)
			cout << "YES\n" << p << '\n';
		else
			cout << "NO\n";
	}

	return 0;
}
