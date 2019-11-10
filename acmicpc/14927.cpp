#include <iostream>
using namespace std;
#define MAX 19
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n;
bool map[MAX][MAX];
bool on[MAX][MAX], off[MAX][MAX];

void push(int x, int y)
{
	off[x][y] ^= 1;
	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx < 0 || nx >= n || ny < 0 || ny >= n)
			continue;

		off[nx][ny] ^= 1;
	}
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cin >> map[i][j];

	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			if (map[i][j] == 1)
				on[i][j] = 1;

	int ans = 1e9+7;
	for (int k=0; k<(1 << n); ++k) {
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				off[i][j] = on[i][j];
		int cnt = 0;
		for (int i=0; i<n; ++i) {
			if ((1 << i) & k) {
				cnt++;
				push(0, i);
			}
		}

		for (int i=1; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				if (off[i-1][j]) {
					cnt++;
					push(i, j);
				}
			}
		}

		bool flag = true;
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				if (off[i][j])
					flag = false;
		if (flag)
			ans = min(ans, cnt);
	}
	if (ans != 1e9+7)
		cout << ans << '\n';
	else
		cout << "-1\n";

	return 0;
}
