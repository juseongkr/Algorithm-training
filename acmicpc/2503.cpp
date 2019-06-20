#include <iostream>
using namespace std;
#define MAX 1001

int num[MAX];

bool check(int k, int q, int S, int B)
{
	int a = q / 100;
	int b = (q % 100) / 10;
	int c = (q % 100) % 10;
	int x = k / 100;
	int y = (k % 100) / 10;
	int z = (k % 100) % 10;
	int strike = 0;
	int ball = 0;

	if (x == 0 || y == 0 || z == 0 || x == y || y == z || x == z)
		return true;

	if (a == x)
		strike++;
	if (b == y)
		strike++;
	if (c == z)
		strike++;

	if (x == b || x == c)
		ball++;
	if (y == a || y == c)
		ball++;
	if (z == a || z == b)
		ball++;

	if (strike == S && ball == B)
		return false;

	return true;
}

int main()
{
	int n, q, s, b, ans = 0;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> q >> s >> b;
		for (int j=123; j<=987; ++j) {
			if (!num[j])
				num[j] = check(j, q, s, b);
		}
	}

	for (int i=123; i<=987; ++i)
		if (!num[i])
			ans++;

	cout << ans << '\n';

	return 0;
}
