#include <iostream>
using namespace std;

int n, r, c, cnt;

void solve(int y, int x, int n)
{
	if (n == 2) {
		if (y == r && x == c) {
			printf("%d\n", cnt);
			return;
		}
		cnt++;
		if (y == r && x + 1 == c) {
			printf("%d\n", cnt);
			return;
		}
		cnt++;
		if (y + 1 == r && x == c) {
			printf("%d\n", cnt);
			return;
		}
		cnt++;
		if (y + 1 == r && x + 1 == c) {
			printf("%d\n", cnt);
			return;
		}
		cnt++;
		return;
	}
	solve(y, x, n/2);
	solve(y, x+n/2, n/2);
	solve(y+n/2, x, n/2);
	solve(y+n/2, x+n/2, n/2);
}

int main()
{
	scanf("%d %d %d", &n, &r, &c);

	solve(0, 0, 1<<n);

	return 0;
}
