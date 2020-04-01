#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9;
typedef vector<vector<long long>> vvl;

int t;
long long n;

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
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		if (n <= 1) {
			cout << n << '\n';
			continue;
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
	}

	return 0;
}
