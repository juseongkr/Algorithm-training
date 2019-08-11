#include <iostream>
using namespace std;
#define MAX 602

int main()
{
	int a[MAX][MAX];
	int h, w, x, y;

	cin >> h >> w >> x >> y;
	for (int i=0; i<h+x; ++i)
		for (int j=0; j<w+y; ++j)
			cin >> a[i][j];

	for (int i=0; i<h; ++i) {
		for (int j=0; j<w; ++j) {
			a[i+x][j+y] -= a[i][j];
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
