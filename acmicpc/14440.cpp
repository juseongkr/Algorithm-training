#include <stdio.h>
#include <vector>
using namespace std;
typedef vector<vector<int>> vvl;
#define MOD 100

int x, y, a, b, n;

vvl operator*(const vvl &a, const vvl &b)
{
	vvl c(2, vector<int>(2));
	for (int i=0; i<2; ++i) {
		for (int j=0; j<2; ++j) {
			for (int k=0; k<2; ++k) {
				c[i][j] += (a[i][k] * b[k][j]) % MOD;
			}
			c[i][j] %= MOD;
		}
	}
	return c;
}

int main()
{
	scanf("%d %d %d %d %d", &x, &y, &a, &b, &n);
	if (n == 0) {
		printf("%02d\n", a);
	} else if (n == 1) {
		printf("%02d\n", b);
	} else {
		vvl mat = {{x, y}, {1, 0}};
		vvl ans = {{1, 0}, {0, 1}};

		n--;
		while (n) {
			if (n % 2)
				ans = ans * mat;
			mat = mat * mat;
			n /= 2;
		}
		printf("%02d\n", (ans[0][0] * b + ans[0][1] * a) % MOD);
	}

	return 0;
}
