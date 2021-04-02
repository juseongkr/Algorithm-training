#include <iostream>
#include <unordered_map>
using namespace std;
const int dxx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dyy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

string q, d, s;
int n, qx, qy, dx, dy;
unordered_map<string, int> dir = {
	{"R", 0},
	{"RT", 1},
	{"T", 2},
	{"LT", 3},
	{"L", 4},
	{"LB", 5},
	{"B", 6},
	{"RB", 7},
};

int main()
{
	cin >> q >> d >> n;
	qx = q[0]-'A';
	qy = 8-(q[1]-'0');
	dx = d[0]-'A';
	dy = 8-(d[1]-'0');

	while (n--) {
		cin >> s;
		int way = dir[s];
		int nx = qx + dxx[way];
		int ny = qy + dyy[way];

		if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8)
			continue;

		if (nx == dx && ny == dy) {
			int nnx = dx + dxx[way];
			int nny = dy + dyy[way];

			if (nnx < 0 || nnx >= 8 || nny < 0 || nny >= 8)
				continue;

			dx = nnx;
			dy = nny;
		}

		qx = nx;
		qy = ny;
	}

	cout << static_cast<char>(qx+'A') + to_string(8-qy) << '\n';
	cout << static_cast<char>(dx+'A') + to_string(8-dy) << '\n';

	return 0;
}
