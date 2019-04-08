#include <iostream>
using namespace std;

int n, cnt;
int check[3][40];

void dfs(int x)
{
	if (x == n) {
		cnt++;
		return;
	}

	for (int i=0; i<n; ++i) {
		if (check[0][i] || check[1][x+i] || check[2][x+n-i])
			continue;

		check[0][i] = check[1][x+i] = check[2][x+n-i] = 1;
		dfs(x+1);
		check[0][i] = check[1][x+i] = check[2][x+n-i] = 0;
	}
}

int main()
{
	scanf("%d", &n);

	dfs(0);

	printf("%d\n", cnt);

	return 0;
}
