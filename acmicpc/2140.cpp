#include <iostream>
using namespace std;
#define MAX 101
const int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int n, ans;
string map[MAX];

bool check(int x, int y)
{
	for (int i=0; i<8; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (map[nx][ny] == '0')
			return false;
	}
	return true;
}

void bfs(int x, int y)
{
	ans++;
	for (int i=0; i<8; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (map[nx][ny] != '0')
			map[nx][ny]--;
	}
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> map[i];

	for (int i=1; i<n-1; ++i)
		for (int j=1; j<n-1; ++j)
			if (check(i, j))
				bfs(i, j);
	cout << ans << '\n';

	return 0;
}
