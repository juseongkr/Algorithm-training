#include <iostream>
#include <vector>
using namespace std;
#define n 8
typedef vector<vector<long long>> vvl;
const int MOD = 1e9+7;

vvl mat = {{0, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 1, 0, 0, 0},
	{0, 1, 1, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 0, 1, 0, 1},
	{0, 0, 0, 1, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 1, 0, 1},
	{0, 0, 0, 0, 1, 0, 1, 0}};

vvl operator*(const vvl &a, const vvl &b)
{
	vvl c(n, vector<long long>(n));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			for (int k=0; k<n; ++k) {
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= MOD;
		}
	}
	return c;
}

int main()
{
	vvl ans(n, vector<long long>(n));
	int d;

	cin >> d;
	for (int i=0; i<n; ++i)
		ans[i][i] = 1;

	while (d) {
		if (d % 2 == 1)
			ans = ans * mat;
		mat = mat * mat;
		d /= 2;
	}

	cout << ans[0][0] << '\n';

	return 0;
}
