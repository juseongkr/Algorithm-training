#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<pair<int, int>> pos;
	int n, m, t, k, x, y, X, Y;

	cin >> n >> m >> t >> k;
	for (int i=0; i<t; ++i) {
		cin >> x >> y;
		pos.push_back({x, y});
	}

	int ans = 0;
	for (int i=0; i<t; ++i) {
		for (int j=0; j<t; ++j) {
			x = pos[i].first;
			if (x + k > n)
				x = n - k;

			y = pos[j].second;
			if (y + k > m)
				y = m - k;

			int cnt = 0;
			for (int p=0; p<pos.size(); ++p) {
				if (x <= pos[p].first && pos[p].first <= x+k && \
					y <= pos[p].second && pos[p].second <= y+k)
					cnt++;
			}
			if (ans < cnt) {
				ans = cnt;
				X = x;
				Y = y+k;
			}
		}
	}
	cout << X << " " << Y << '\n' << ans << '\n';

	return 0;
}
