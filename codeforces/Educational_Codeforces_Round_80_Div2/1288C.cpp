#include <iostream>
using namespace std;
#define MAX 1100
#define ll long long
const int MOD = 1e9+7;

ll n, m;
ll c[MAX][MAX];

int main()
{
	cin >> n >> m;

	c[0][0] = 1;
	for (int i=1; i<MAX; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j=1; j<i; ++j)
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MOD;
	}

	cout << c[2*m+n-1][2*m] << '\n';

	return 0;
}
