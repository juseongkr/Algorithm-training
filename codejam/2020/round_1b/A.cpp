#include <iostream>
#include <set>
using namespace std;
#define ll long long

char d[4] = {'W', 'S', 'N', 'E'};
int T, x, y;

int check(string s, int x, int y)
{
	for (int i=0; i<s.length(); ++i) {
		if (s[i] == 'W')
			x += (1 << i);
		if (s[i] == 'E')
			x -= (1 << i);
		if (s[i] == 'S')
			y += (1 << i);
		if (s[i] == 'N')
			y -= (1 << i);
	}

	if (x == 0 && y == 0)
		return 1;
	if (x % (1 << s.length()) || y % (1 << s.length()))
		return -1;
	return 0;
}

int main()
{
	cin >> T;
	for (int t=1; t<=T; ++t) {
		cin >> x >> y;

		set<string> visit[41];
		visit[0].insert("");
		string ans;
		bool flag = false;
		for (int i=0; i<40; ++i) {
			for (auto j : visit[i]) {
				for (int k=0; k<4; ++k) {
					string next = j + d[k];
					int ret = check(next, x, y);
					if (ret == 1) {
						ans = next;
						flag = true;
						cout << "Case #" << t << ": " << ans << '\n';
						break;
					} else if (ret == 0) {
						visit[i+1].insert(next);
					}
				}
			}
			if (flag)
				break;
		}
		if (!flag)
			cout << "Case #" << t << ": IMPOSSIBLE\n";
	}

	return 0;
}
