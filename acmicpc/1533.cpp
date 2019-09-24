#include <iostream>
#include <vector>
using namespace std;
#define MAX 51
#define MOD 1000003
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
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	string str;
	int n, s, e, t;

	cin >> n >> s >> e >> t;
	vvl mat(n*5, vector<long long>(n*5));
	vvl ans(n*5, vector<long long>(n*5));
	for (int i=0; i<n*5; ++i)
		ans[i][i] = 1;

	for (int i=0; i<n; ++i)
		for (int j=0; j<4; ++j)
			mat[i*5+j][i*5+j+1] = 1;

	for (int i=0; i<n; ++i) {
		cin >> str;
		for (int j=0; j<n; ++j) {
			int v = str[j]-'0';
			if (v)
				mat[i*5+v-1][j*5] = 1;
		}
	}

	while (t) {
		if (t % 2 == 1)
			ans = ans * mat;
		mat = mat * mat;
		t /= 2;
	}
	cout << ans[(s-1)*5][(e-1)*5] << '\n';

	return 0;
}
