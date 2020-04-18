#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9+7;
typedef vector<vector<long long>> vvl;

vvl operator*(const vvl &a, const vvl &b)
{
	long long n = a.size();
	vvl c(n, vector<long long>(n));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			for (int k=0; k<n; ++k) {
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}
	return c;
}

int main()
{
	int m;
	long long n;

	cin >> n >> m;
	if (n-m+1 <= 0) {
		cout << "1\n";
		return 0;
	}

	vvl mat(m, vector<long long>(m, 0));
	vvl ans(m, vector<long long>(m, 0));

	for (int i=0; i<m-1; ++i)
		mat[i][i+1] = ans[i][i] = 1;
	mat[m-1][0] = mat[m-1][m-1] = ans[m-1][m-1] = 1;

	long long k = n-m+1;
	while (k) {
		if (k % 2 == 1)
			ans = ans * mat;
		mat = mat * mat;
		k /= 2;
	}

	long long sum = 0;
	for (int i=0; i<m; ++i)
		sum = (sum + ans[m-1][i]) % MOD;

	cout << sum << '\n';

	return 0;
}
