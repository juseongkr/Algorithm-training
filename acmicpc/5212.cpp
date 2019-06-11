#include <iostream>
using namespace std;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

string s;
char map[12][12], after[12][12];
int r, c, ax, ay, bx, by;

void dfs(int y, int x)
{
	int cnt = 0;
	for (int i=0; i<4; ++i) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];
		if (map[next_y][next_x] == '.')
			cnt++;
	}
	if (cnt >= 3)
		after[y][x] = '.';
}

int main()
{
	cin >> r >> c;
	for (int i=0; i<r+2; ++i)
		for (int j=0; j<c+2; ++j)
			after[i][j] = map[i][j] = '.';

	for (int i=1; i<r+1; ++i) {
		cin >> s;
		for (int j=1; j<c+1; ++j)
			after[i][j] = map[i][j] = s[j-1];
	}

	for (int i=1; i<r+1; ++i)
		for (int j=1; j<c+1; ++j)
			if (map[i][j] == 'X')
				dfs(i, j);

	for (int i=0; i<r+2; ++i) {
		for (int j=0; j<c+2; ++j) {
			if (after[i][j] == 'X' && !ax)
				ax = i;
			if (after[i][j] == 'X')
				ay = max(ay, i);
		}
	}

	for (int j=0; j<c+2; ++j) {
		for (int i=0; i<r+2; ++i) {
			if (after[i][j] == 'X' && !bx)
				bx = j;
			if (after[i][j] == 'X')
				by = max(by, j);
		}
	}

	for (int i=ax; i<=ay; ++i) {
		for (int j=bx; j<=by; ++j)
			cout << after[i][j];
		cout << '\n';
	}

	return 0;
}
