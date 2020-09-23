#include <iostream>
#include <vector>
using namespace std;
#define MAxpos 21

int n;
int map[MAxpos][MAxpos];

int solve(int x1, int y1, int x2, int y2, int cut)
{
	if (x1 == x2 || y1 == y2)
		return 0;

	vector<int> xpos, ypos;
	int dirty = 0, jewel = 0;

	for (int i=x1; i<x2; ++i) {
		for (int j=y1; j<y2; ++j) {
			if (map[i][j] == 1) {
				xpos.push_back(i);
				ypos.push_back(j);
				dirty++;
			} else if (map[i][j] == 2) {
				jewel++;
			}
		}
	}

	if (jewel == 0 && (jewel >= 2 && dirty == 0))
		return 0;

	if (jewel == 1)
		return dirty == 0 ? 1 : 0;

	int cnt = 0;
	if (cut != 1) {
		for (auto y : ypos) {
			bool flag = true;
			for (int i=x1; i<x2; ++i) {
				if (map[i][y] == 2) {
					flag = false;
					break;
				}
			}

			if (flag) {
				cnt += solve(x1, y1, x2, y, 1) * \
				       solve(x1, y+1, x2, y2, 1);
			}
		}
	}

	if (cut != 2) {
		for (auto x : xpos) {
			bool flag = true;
			for (int i=y1; i<y2; ++i) {
				if (map[x][i] == 2) {
					flag = false;
					break;
				}
			}

			if (flag) {
				cnt += solve(x1, y1, x, y2, 2) * \
				       solve(x+1, y1, x2, y2, 2);
			}
		}
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cin >> map[i][j];

	int ans = solve(0, 0, n, n, 0);
	if (ans)
		cout << ans << '\n';
	else
		cout << "-1\n";

	return 0;
}
