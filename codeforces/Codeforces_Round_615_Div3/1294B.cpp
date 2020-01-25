#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int t, n, u, v;

	cin >> t;
	while (t--) {
		vector<tuple<int, int, int>> vec;
		cin >> n;
		for (int i=0; i<n; ++i) {
			cin >> u >> v;
			vec.push_back({u+v, u, v});
		}

		sort(vec.begin(), vec.end());

		string ans;
		bool flag = true;
		int sx = 0, sy = 0;
		for (int i=0; i<n; ++i) {
			auto [_, x, y] = vec[i];

			if (x < sx || y < sy) {
				flag = false;
				break;
			}

			for (int j=0; j<x-sx; ++j)
				ans += "R";
			for (int j=0; j<y-sy; ++j)
				ans += "U";

			sx = x;
			sy = y;
		}

		if (flag) {
			cout << "YES\n";
			cout << ans << '\n';
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}
