#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<long long>> vvl;
const int MOD = 1e9+7;;

int n, k, m;

vvl operator*(const vvl &a, const vvl &b)
{
	vvl c(m, vector<long long>(m));
	for (int i=0; i<m; ++i) {
		for (int j=0; j<m; ++j) {
			for (int k=0; k<m; ++k) {
				c[i][j] += (a[i][k] * b[k][j]) % MOD;
			}
			c[i][j] %= MOD;
		}
	}
	return c;
}

int main()
{
	cin >> k >> n;
	m = k+2;
	vvl mat(m, vector<long long>(m, 0));
	vvl ans(m, vector<long long>(m, 0));

	for (int i=0; i<m; ++i)
		for (int j=0; j<=i; j++)
			mat[i][j] = 1;

	for (int i=0; i<m; ++i)
		ans[i][i] = 1;

	int d = n-1;
	while (d) {
		if (d % 2)
			ans = ans * mat;
		mat = mat * mat;
		d /= 2;
	}

	int ret = 0;
	for (int i=0; i<m; ++i)
		ret = (ret + ans[m-1][i]) % MOD;

	cout << ret << '\n';

	return 0;
}
