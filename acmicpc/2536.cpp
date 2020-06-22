#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 100001
typedef tuple<int, int, int, int> tp;

int n, m, k, p, x1, x2, y1, y2, sx, sy, dx, dy;
bool visit[MAX];
vector<tp> bus;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=0; i<k; ++i) {
		cin >> p >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2)
			swap(x1, x2);
		if (y1 > y2)
			swap(y1, y2);
		bus.push_back({x1, y1, x2, y2});
	}
	cin >> sx >> sy >> dx >> dy;

	queue<pair<int, int>> que;
	
	for (int i=0; i<k; ++i) {
		auto [x1, y1, x2, y2] = bus[i];
		if (x1 <= sx && sx <= x2 && y1 <= sy && sy <= y2) {
			que.push({i, 0});
			visit[i] = 1;
		}
	}

	while (!que.empty()) {
		auto [cur, cnt] = que.front();
		que.pop();

		auto [x1, y1, x2, y2] = bus[cur];
		if (x1 <= dx && dx <= x2 && y1 <= dy && dy <= y2) {
			cout << cnt+1 << '\n';
			return 0;
		}

		for (int i=0; i<k; ++i) {
			auto [u1, v1, u2, v2] = bus[i];
			if (!visit[i] && u1 <= x2 && u2 >= x1 && v1 <= y2 && v2 >= y1) {
				que.push({i, cnt+1});
				visit[i] = 1;
			}
		}
	}

	return 0;
}
