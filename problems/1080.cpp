#include <iostream>
using namespace std;

char a[51][51], b[51][51];

void flip(int x, int y)
{
	for (int i=x; i<x+3; ++i)
		for (int j=y; j<y+3; ++j)
			if (a[i][j] == '0')
				a[i][j] = '1';
			else
				a[i][j] = '0';
}

int main()
{
	int n, m, cnt = 0;

	cin >> n >> m;

	for (int i=0; i<n; ++i)
		scanf("%s", a[i]);

	for (int i=0; i<n; ++i)
		scanf("%s", b[i]);
	
	for (int i=0; i<n-2; ++i) {
		for (int j=0; j<m-2; ++j) {
			if (a[i][j] != b[i][j]) {
				cnt++;
				flip(i, j);
			}
		}
	}

	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (a[i][j] != b[i][j]) {
				cout << "-1" << '\n';
				return 0;
			}

	cout << cnt << '\n';

	return 0;
}
