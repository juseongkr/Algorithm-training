#include <iostream>
using namespace std;

int t[16], p[16], dp[16];
int n;

int solve(int d)
{
	if (d == n + 1)
		return 0;
	if (d > n + 1)
		return -1000*16;

	return max(solve(d + 1), solve(d + t[d]) + p[d]);
}

int main()
{
	int x, y;

	scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		scanf("%d %d", &x, &y);
		t[i] = x;
		p[i] = y;
	}

	printf("%d\n", solve(1));

	return 0;
}
