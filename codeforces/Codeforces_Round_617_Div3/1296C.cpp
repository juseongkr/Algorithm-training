#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9+7;

int n, t;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> s;

		bool flag = false;
		int l = 0, r = 0, x = 0, y = 0, ans = INF;
		map<pair<int, int>, int> m;
		m[{0, 0}] = 0;
		for (int i=0; i<n; ++i) {
			if (s[i] == 'L')
				x -= 1;
			else if (s[i] == 'R')
				x += 1;
			else if (s[i] == 'U')
				y -= 1;
			else
				y += 1;

			if (m.count({x, y})) {
				flag = true;
				int len = (i+1) - m[{x, y}];
				if (ans > len) {
					l = m[{x, y}]+1;
					r = i+1;
					ans = len;
				}
			}
			m[{x, y}] = i+1;
		}
		if (flag)
			cout << l << " " << r << '\n';
		else
			cout << "-1\n";
	}

	return 0;
}
