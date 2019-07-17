#include <iostream>
using namespace std;
#define MAX 21

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
char board[MAX][MAX];
bool flag;
int n, m;

int solve(int y1, int x1, int y2, int x2, int cnt)
{
	if (cnt == 11)
		return -1;

	bool A = false, B = false;
	if (y1 < 0 || x1 < 0 || y1 >= n || x1 >= m)
		A = true;
	if (y2 < 0 || x2 < 0 || y2 >= n || x2 >= m)
		B = true;

	if (A && B)
		return -1;
	if (A || B)
		return cnt;

	int ans = 11;
	for (int i=0; i<4; ++i) {
		int next_y1 = y1 + dy[i];
		int next_x1 = x1 + dx[i];
		int next_y2 = y2 + dy[i];
		int next_x2 = x2 + dx[i];

		if (next_y1 >= 0 && next_x1 >= 0 && next_y1 < n && next_x1 < m && board[next_y1][next_x1] == '#') {
			next_y1 = y1;
			next_x1 = x1;
		}

		if (next_y2 >= 0 && next_x2 >= 0 && next_y2 < n && next_x2 < m && board[next_y2][next_x2] == '#') {
			next_y2 = y2;
			next_x2 = x2;
		}

		int ret = solve(next_y1, next_x1, next_y2, next_x2, cnt+1);
		if (ret == -1)
			continue;
		ans = min(ans, ret);
	}
	return ans;
}

int main()
{
	int y1, x1, y2, x2;

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 'o') {
				if (!flag) {
					y1 = i;
					x1 = j;
					flag = true;
				} else {
					y2 = i;
					x2 = j;
				}

			}
		}
	}

	int ans = solve(y1, x1, y2, x2, 0);
	if (ans == 11)
		cout << "-1\n";
	else
		cout << ans << '\n';

	return 0;
}
