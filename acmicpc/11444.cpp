#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007
typedef vector<vector<long long>> vvl;

vvl operator*(const vvl &a, const vvl &b)
{
	int n = a.size();
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
	long long n;

	cin >> n;
	if (n <= 1) {
		cout << n << '\n';
		return 0;
	}
	vvl ans = {{1, 0},
		   {0, 1}};
	vvl mat = {{1, 1},
		   {1, 0}};

	n--;
	while (n) {
		if (n % 2 == 1)
			ans = ans * mat;
		mat = mat * mat;
		n /= 2;
	}
	cout << ans[0][0] << '\n';

	return 0;
}
