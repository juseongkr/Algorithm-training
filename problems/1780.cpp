#include <iostream>
using namespace std;

int matrix[2188][2188], result[3];

void solve(int x, int y, int n)
{
	bool flag = true;
	for (int i=x; i<x+n; ++i)
		for (int j=y; j<y+n; ++j)
			if (matrix[x][y] != matrix[i][j])
				flag = false;

	if (flag) {
		result[matrix[x][y]+1]++;
		return;
	}

	for (int i=0; i<3; ++i)
		for (int j=0; j<3; ++j)
			solve(x + (n/3) * i, y + (n/3) * j, n/3);
}

int main()
{
	int n;

	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			scanf("%d", &matrix[i][j]);

	solve(0, 0, n);

	for (int i=0; i<3; ++i)
		printf("%d\n", result[i]);

	return 0;
}
