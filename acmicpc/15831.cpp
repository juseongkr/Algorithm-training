#include <iostream>
using namespace std;

int n, B, W;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> B >> W >> s;

	int black = 0, white = 0;
	int l = 0, r = 0, ans = 0;
	while (l < n && r < n) {
		if (s[r++] == 'W')
			white++;
		else
			black++;

		if (black <= B && W <= white) {
			ans = max(ans, r-l);
			continue;
		}

		if (black > B) {
			if (s[l++] == 'W')
				white--;
			else
				black--;
		}
	}
	cout << ans << '\n';

	return 0;
}
