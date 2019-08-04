#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> vvi;

int n;

vvi operator*(const vvi &a, const vvi &b)
{
	vvi c(n, vector<int>(n));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			for (int k=0; k<n; ++k) {
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= 1000;
		}
	}
	return c;
}

int main()
{
	long long b;
	cin >> n >> b;

	vvi mat(n, vector<int>(n));
	vvi ans(n, vector<int>(n));

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j)
			cin >> mat[i][j];
		ans[i][i] = 1;
	}

	while (b) {
		if (b % 2 == 1)
			ans = ans * mat;
		mat = mat * mat;
		b /= 2;
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j)
			cout << ans[i][j] << " ";
		cout << '\n';
	}

	return 0;
}
