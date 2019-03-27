#include <iostream>
using namespace std;

int video[65][65];

void solve(int x, int y, int s)
{
	bool flag = true;
	for (int i=x; i<x+s; ++i)
		for (int j=y; j<y+s; ++j)
			if (video[x][y] != video[i][j])
				flag = false;

	if (flag) {
		printf("%d", video[x][y]);
		return;
	}

	printf("(");
	for (int i=0; i<2; ++i)
		for (int j=0; j<2; ++j)
			solve(x + i * (s/2), y + j * (s/2), s/2);
	printf(")");
}

int main()
{
	string str[65];
	int n;
	
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		cin >> str[i];

	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			video[i][j] = str[i][j] - '0';

	solve(0, 0, n);
	printf("\n");

	return 0;
}
