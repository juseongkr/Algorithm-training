#include <iostream>
using namespace std;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int T, x, y;
string s;

int way(char c)
{
	if (c == 'N')
		return 1;
	else if (c == 'W')
		return 2;
	else if (c == 'S')
		return 3;
	return 0;
}

int main()
{
	cin >> T;
	for (int t=1; t<=T; ++t) {
		cin >> x >> y >> s;

		int ans = -1;
		for (int i=0; i<s.length(); ++i) {
			int d = way(s[i]);
			x += dx[d];
			y += dy[d];
			if (abs(x) + abs(y) <= i+1) {
				ans = i+1;
				break;
			}
		}
		if (ans == -1)
			cout << "Case #" << t << ": IMPOSSIBLE\n";
		else
			cout << "Case #" << t << ": " << ans << '\n';
	}
}
