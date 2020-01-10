#include <iostream>
#include <vector>
using namespace std;
#define MAX 10050

int t, n, x, y;
bool map[MAX][MAX];
vector<pair<int, int>> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; ++i) {
			cin >> x >> y;
			x += 10;
			y += 10;
			map[x][y] = 1;
			vec.push_back({x, y});
		}

		int ans = 0, cnt = 0;
		for (int i=0; i<n; ++i) {
			auto [X, Y] = vec[i];
			cnt = 0;
			for (int a=X; a<=X+10; ++a)
				for (int b=Y; b<=Y+10; ++b)
					if (map[a][b])
						cnt++;
			ans = max(ans, cnt);
			cnt = 0;

			for (int a=X; a<=X+10; ++a)
				for (int b=Y-10; b<=Y; ++b)
					if (map[a][b])
						cnt++;
			ans = max(ans, cnt);
			cnt = 0;

			for (int a=X-10; a<=X; ++a)
				for (int b=Y; b<=Y+10; ++b)
					if (map[a][b])
						cnt++;
			ans = max(ans, cnt);
			cnt = 0;

			for (int a=X-10; a<=X; ++a)
				for (int b=Y-10; b<=Y; ++b)
					if (map[a][b])
						cnt++;
			ans = max(ans, cnt);
			cnt = 0;
		}
		cout << ans << '\n';

		vec.clear();
		for (int i=0; i<n; ++i) {
			auto [X, Y] = vec[i];
			map[X][Y] = 0;
		}
	}

	return 0;
}
