#include <iostream>
using namespace std;

int x, y, nx, ny, sx, sy;
bool visit[6][6];

bool check(int x, int y, int nx, int ny)
{
	return ((abs(nx-x) == 1 && abs(ny-y) == 2) || (abs(nx-x) == 2 && abs(ny-y) == 1));
}

int main()
{
	bool flag = true;
	string s;

	for (int i=0; i<36; ++i) {
		cin >> s;

		x = s[0]-'A';
		y = s[1]-'1';
		if (visit[x][y])
			flag = false;
		visit[x][y] = true;

		if (i == 0) {
			sx = x;
			sy = y;
		} else if (!check(x, y, nx, ny)) {
			flag = false;
		}
		nx = x;
		ny = y;
	}
	if (!check(x, y, sx, sy))
		flag = false;

	if (flag)
		cout << "Valid\n";
	else
		cout << "Invalid\n";

	return 0;
}
