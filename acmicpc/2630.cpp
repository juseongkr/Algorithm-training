#include <iostream>
using namespace std;
#define MAX 128

int num[MAX][MAX];
int n, w, b;

void solve(int y, int x, int r)
{
	if (n == 1) {
		if (num[y][x] == 1)
			b++;
		else
			w++;
	} else {
		bool flag = true;
		for (int i=y; i<y+r; ++i) {
			for (int j=x; j<x+r; ++j) {
				if (num[y][x] != num[i][j]) {
					flag = false;
					break;
				}
			}
		}

		if (flag) {
			if (num[y][x] == 1)
				b++;
			else
				w++;
		} else {
			solve(y, x, r/2);
			solve(y, x+r/2, r/2);
			solve(y+r/2, x, r/2);
			solve(y+r/2, x+r/2, r/2);
		}
	}
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cin >> num[i][j];

	solve(0, 0, n);

	cout << w << '\n' << b << '\n';

	return 0;
}
