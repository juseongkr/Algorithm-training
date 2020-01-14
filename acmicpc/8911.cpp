#include <iostream>
using namespace std;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int t;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> s;
		int L = 0, R = 0, U = 0, D = 0, d = 0, x = 0, y = 0;
		for (int i=0; i<s.length(); ++i) {
			if (s[i] == 'L') {
				d = (d+3) % 4;
			} else if (s[i] == 'R') {
				d = (d+1) % 4;
			} else if (s[i] == 'F') {
				x += dx[d];
				y += dy[d];
			} else {
				x -= dx[d];
				y -= dy[d];
			}
			L = min(L, x);
			R = max(R, x);
			U = max(U, y);
			D = min(D, y);
		}
		cout << (R-L) * (U-D) << '\n';
	}

	return 0;
}
