#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000000
typedef vector<vector<long long>> vvl;

vvl operator*(const vvl &a, const vvl &b)
{
	long long n = a.size();
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
	long long a, b;

	cin >> a >> b;
	vvl mat(2, vector<long long>(2));
	mat = {{1, 1}, {1, 0}};
	
	b += 2;
	vvl x(2, vector<long long>(2));
	x = {{1, 0}, {0, 1}};
	while (b) {
		if (b % 2 == 1)
			x = x * mat;
		mat = mat * mat;
		b /= 2;
	}

	a += 1;
	mat = {{1, 1}, {1, 0}};
	vvl y(2, vector<long long>(2));
	y = {{1, 0}, {0, 1}};
	while (a) {
		if (a % 2 == 1)
			y = y * mat;
		mat = mat * mat;
		a /= 2;
	}

	cout << ((x[0][1]-1) - (y[0][1]-1) + MOD) % MOD << '\n';

	return 0;
}
