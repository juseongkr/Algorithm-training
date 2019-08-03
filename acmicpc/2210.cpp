#include <iostream>
#include <set>
using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
set<int> st;
int map[5][5];

void dfs(int x, int y, int num, int cnt)
{
	if (cnt == 6) {
		st.insert(num);
		return;
	}

	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
			continue;

		dfs(nx, ny, num * 10 + map[nx][ny], cnt+1);
	}
}

int main()
{
	for (int i=0; i<5; ++i)
		for (int j=0; j<5; ++j)
			cin >> map[i][j];

	for (int i=0; i<5; ++i) {
		for (int j=0; j<5; ++j) {
			dfs(i, j, map[i][j], 1);
		}
	}

	cout << st.size() << '\n';

	return 0;
}
