#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<bool>> vvb;

int n, k, m, a, b;

vvb operator*(const vvb &a, const vvb &b)
{
	vvb ret(n, vector<bool>(n));
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			for (int k=0; k<n; ++k)
				if (a[i][k] && b[k][j])
					ret[i][j] = true;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k >> m;
	vvb map(n, vector<bool>(n));
	vvb ans(n, vector<bool>(n));
	for (int i=0; i<n; ++i) {
		cin >> a >> b;
		map[i][a-1] = map[i][b-1] = true;
	}

	for (int i=0; i<n; ++i)
		ans[i][i] = true;

	while (k) {
		if (k % 2 == 1)
			ans = ans * map;
		map = map * map;
		k /= 2;
	}

	for (int i=0; i<m; ++i) {
		cin >> a >> b;
		if (ans[a-1][b-1])
			cout << "death\n";
		else
			cout << "life\n";
	}

	return 0;
}
