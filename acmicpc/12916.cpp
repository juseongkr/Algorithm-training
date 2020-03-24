#include <iostream>
#include <vector>
using namespace std;
#define MAX 101
const int MOD = 1e9+7;
typedef vector<vector<long long>> vvl;

int n, k;

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
	cin >> n >> k;
	vvl mat(n, vector<long long>(n));
	vvl ans(n, vector<long long>(n));

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j)
			cin >> mat[i][j];
		ans[i][i] = 1;
	}

	while (k) {
		if (k % 2 == 1)
			ans = ans * mat;
		mat = mat * mat;
		k /= 2;
	}

	long long cnt = 0;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cnt = (cnt + ans[i][j]) % MOD;

	cout << cnt << '\n';

	return 0;
}
