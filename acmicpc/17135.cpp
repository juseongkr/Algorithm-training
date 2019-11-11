#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define MAX 16

vector<pair<int, int>> dead;
int n, m, d, cnt, ans;
bool archer[MAX];
int map[MAX][MAX], copy_map[MAX][MAX];

int dist(int x, int y, int a, int b)
{
	return abs(x-a) + abs(y-b);
}

void attack(int k)
{
	vector<tuple<int, int, int>> tar;

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (!copy_map[i][j])
				continue;

			int di = dist(i, j, n, k);
			if (di <= d)
				tar.push_back({di, j, i});
		}
	}

	if (tar.size() == 0)
		return;

	sort(tar.begin(), tar.end());
	auto [_, y, x] = tar[0];
	dead.push_back({x, y});
}

void move()
{
	for (int i=n-2; i>=0; i--)
		for (int j=0; j<m; ++j)
			copy_map[i+1][j] = copy_map[i][j];

	for (int i=0; i<m; ++i)
		copy_map[0][i] = 0;
}

void place(int p)
{
	if (p == 3) {
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				copy_map[i][j] = map[i][j];

		cnt = 0;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j)
				if (archer[j])
					attack(j);

			dead.erase(unique(dead.begin(), dead.end()), dead.end());
			for (int j=0; j<dead.size(); ++j) {
				auto [x, y] = dead[j];
				copy_map[x][y] = 0;
				cnt++;
			}

			dead.clear();
			move();
		}
		ans = max(ans, cnt);
		return;
	}

	for (int i=0; i<m; ++i) {
		if (archer[i])
			continue;

		archer[i] = true;
		place(p+1);
		archer[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> d;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	place(0);
	cout << ans << '\n';

	return 0;
}
