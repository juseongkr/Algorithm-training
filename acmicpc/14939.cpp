#include <iostream>
using namespace std;
#define MAX 11
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

bool on[MAX][MAX], off[MAX][MAX];
char map[MAX][MAX];

void push(int x, int y)
{
	off[x][y] ^= 1;
	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10)
			continue;

		off[nx][ny] ^= 1;
	}
}

int main()
{
	for (int i=0; i<10; ++i)
		cin >> map[i];

	for (int i=0; i<10; ++i)
		for (int j=0; j<10; ++j)
			if (map[i][j] == 'O')
				on[i][j] = 1;

	int ans = 1e9+7;
	for (int k=0; k<(1 << 10); ++k) {
		for (int i=0; i<10; ++i)
			for (int j=0; j<10; ++j)
				off[i][j] = on[i][j];
		int cnt = 0;
		for (int i=0; i<10; ++i) {
			if ((1 << i) & k) {
				cnt++;
				push(0, i);
			}
		}

		for (int i=1; i<10; ++i) {
			for (int j=0; j<10; ++j) {
				if (off[i-1][j]) {
					cnt++;
					push(i, j);
				}
			}
		}

		bool flag = true;
		for (int i=0; i<10; ++i)
			for (int j=0; j<10; ++j)
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
