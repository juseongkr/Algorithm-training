#include <iostream>
using namespace std;
#define MAX 16

int num[MAX][MAX];
pair<int, int> dest;

int solve(int a, int b)
{
	if (a == 1 || b == 1)
		return 1;

	num[a][b] = solve(a, b-1) + solve(a-1, b);
	return num[a][b];
}

int main()
{
	int n, m, k, y, x, t = 0;
	cin >> n >> m >> k;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			num[i][j] = ++t;
			if (t == k) {
				y = i;
				x = j;
			}
		}
	}

	if (k != 0)
		cout << solve(y, x) * solve(n-y+1, m-x+1) << '\n';
	else
		cout << solve(n, m) << '\n';

	return 0;
}
