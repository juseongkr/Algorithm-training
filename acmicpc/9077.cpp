#include <iostream>
#include <cstring>
using namespace std;
#define MAX 10001
const int INF = 1e4;

int t, n, u, v;
int map[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		int ans = 0;
		for (int i=0; i<n; ++i) {
			cin >> u >> v;

			for (int x=-5; x<=5; ++x) {
				for (int y=-5; y<=5; ++y) {
					int nx = x + u;
					int ny = y + v;

					if (nx < 0 || nx >= INF || ny < 0 || ny >= INF)
						continue;

					ans = max(ans, ++map[nx][ny]);
				}
			}
		}

		cout << ans << '\n';

		memset(map, 0, sizeof(map));
	}

	return 0;
}
