#include <iostream>
using namespace std;
#define MAX 1001
const int MOD = 1e9+7;

int t, a, b;
long long c[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	c[0][0] = 1;
	for (int i=1; i<MAX; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j=1; j<i; ++j) {
			c[i][j] = c[i-1][j-1] + c[i-1][j];
			c[i][j] %= MOD;
		}
	}

	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << c[a][b] << '\n';
	}
	
	return 0;
}
