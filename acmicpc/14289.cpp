#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<long long>> vvl;
const int MOD = 1e9+7;

int n, m, x, y, d;
vvl mat, ans;

vvl operator*(const vvl &a, const vvl &b)
{
	vvl c(n, vector<long long>(n));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			for (int k=0; k<n; ++k) {
				c[i][j] += (a[i][k] * b[k][j]) % MOD;
			}
			c[i][j] %= MOD;
		}
	}
	return c;
}

int main()
{
	cin >> n >> m;
	mat.resize(n);
	ans.resize(n);
	for (int i=0; i<n; ++i) {
		mat[i].resize(n);
		ans[i].resize(n);
	}
	
	for (int i=0; i<n; ++i)
		ans[i][i] = 1;

	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		x--;
		y--;
		mat[x][y] = mat[y][x] = 1;
	}

	cin >> d;
	while (d) {
		if (d % 2)
			ans = ans * mat;
		mat = mat * mat;
		d /= 2;
	}

	cout << ans[0][0] << '\n';

	return 0;
}
