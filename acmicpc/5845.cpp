#include <iostream>
#include <set>
using namespace std;
typedef pair<int, int> pi;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dyy[8] = {1, 0, -1, 0, -1, 1, 1, -1};

int n, x, y, ans;
set<pi> map, visit;

bool out(int x, int y)
{
	for (int i=0; i<8; ++i) {
		int nx = x + dxx[i];
		int ny = y + dyy[i];

		if (map.count({nx, ny}))
			return false;
	}
	return true;
}

void dfs(int x, int y)
{
	if (map.count({x, y})) {
		ans++;
		return;
	}

	if (out(x, y))
		return;

	visit.insert({x, y});
	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!visit.count({nx, ny}))
			dfs(nx, ny);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		map.insert({x, y});
	}

	auto [x, y] = *map.begin();
	dfs(x-1, y);

	cout << ans << '\n';

	return 0;
}
