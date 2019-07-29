#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define MAX 101
typedef tuple<int, int, int> t3;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
int r, c, m, a, b, s, d, z;
vector<t3> shark[MAX][MAX], next_shark[MAX][MAX];

int main()
{
	cin >> r >> c >> m;
	for (int i=0; i<m; ++i) {
		cin >> a >> b >> s >> d >> z;
		shark[a-1][b-1].push_back({z, s, d-1});
	}

	int ans = 0;
	for (int i=0; i<c; ++i) {
		for (int j=0; j<r; ++j) {
			if (shark[j][i].size() == 0)
				continue;

			ans += get<0>(shark[j][i][0]);
			shark[j][i].clear();
			break;
		}

		for (int y=0; y<r; ++y) {
			for (int x=0; x<c; ++x) {
				if (shark[y][x].size() == 0)
					continue;

				for (int k=0; k<shark[y][x].size(); ++k) {
					auto [size, speed, dir] = shark[y][x][k];
					int ny = y;
					int nx = x;
					for (int p=0; p<speed; ++p) {
						if (dir == 0) {
							if (ny == 0) {
								ny = 1;
								dir = 1;
							} else {
								ny--;
							}
						} else if (dir == 1) {
							if (ny == r-1) {
								ny = r-2;
								dir = 0;
							} else {
								ny++;
							}
						} else if (dir == 2) {
							if (nx == c-1) {
								nx = c-2;
								dir = 3;
							} else {
								nx++;
							}
						} else {
							if (nx == 0) {
								nx = 1;
								dir = 2;
							} else {
								nx--;
							}
						}
					}
					next_shark[ny][nx].push_back({size, speed, dir});
				}
			}
		}

		for (int y=0; y<r; ++y) {
			for (int x=0; x<c; ++x) {
				shark[y][x].clear();
				if (next_shark[y][x].size() == 0)
					continue;

				sort(next_shark[y][x].rbegin(), next_shark[y][x].rend());
				shark[y][x] = {next_shark[y][x][0]};
				next_shark[y][x].clear();
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
