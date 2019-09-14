#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9+7;
typedef vector<vector<long long>> vvl;

long long gcd(long long a, long long b)
{
	return b ? gcd(b, a%b) : a;
}

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

long long fibo(long long n)
{
	vvl mat(2, vector<long long>(2));
	mat = {{1, 1}, {1, 0}};

	vvl ans(2, vector<long long>(2));
	ans = {{1, 0}, {0, 1}};

	while (n) {
		if (n % 2 == 1)
			ans = ans * mat;
		mat = mat * mat;
		n /= 2;
	}
	return ans[0][1];
}

int main()
{
	long long n, m;

	cin >> n >> m;
	cout << fibo(gcd(n, m)) << '\n';

	return 0;
}
