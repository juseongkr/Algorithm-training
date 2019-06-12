#include <iostream>
using namespace std;
#define MAX 250

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int main()
{
	int next_y, next_x, max_x, max_y, min_x, min_y;
	char map[MAX][MAX];
	int n, pos = 2;
	string s;

	cin >> n >> s;
	next_y = next_x = max_x = max_y = min_x = min_y = 50;
	for (int i=0; i<MAX; ++i) {
		for (int j=0; j<MAX; ++j) {
			if (i == 50 && j == 50)
				map[i][j] = '.';
			else
				map[i][j] = '#';
		}
	}

	for (int i=0; i<s.length(); ++i) {
		if (s[i] == 'F') {
			next_y += dy[pos];
			next_x += dx[pos];
			map[next_y][next_x] = '.';
			max_y = max(max_y, next_y);
			min_y = min(min_y, next_y);
			max_x = max(max_x, next_x);
			min_x = min(min_x, next_x);
		} else if (s[i] == 'R') {
			pos = (pos+1) % 4;
		} else {
			if (pos == 0)
				pos = 3;
			else
				pos--;
		}
	}

	for (int i=min_y; i<=max_y; ++i) {
		for (int j=min_x; j<=max_x; ++j)
			cout << map[i][j];
		cout << '\n';
	}

	return 0;
}
