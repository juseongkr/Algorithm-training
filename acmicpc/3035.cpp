#include <iostream>
using namespace std;
#define MAX 51

int main()
{
	char map[MAX][MAX];
	int r, c, zr, zc;

	cin >> r >> c >> zr >> zc;
	for (int i=0; i<r; ++i)
		for (int j=0; j<c; ++j)
			cin >> map[i][j];

	for (int i=0; i<r; ++i) {
		for (int y=0; y<zr; ++y) {
			for (int j=0; j<c; ++j) {
				for (int x=0; x<zc; ++x) {
					cout << map[i][j];
				}
			}
			cout << '\n';
		}
	}
	return 0;
}
