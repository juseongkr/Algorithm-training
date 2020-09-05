#include <iostream>
using namespace std;
#define MAX 1000001
const int MOD = 1e9+7;

int n;
int f[MAX], g[MAX];

int main()
{
	cin >> n;
	f[1] = 2;
	f[0] = g[1] = 1;
	for (int i=2; i<=n; ++i) {
		g[i] = ((f[i-1] + f[i-2]) % MOD + g[i-2]) % MOD;
		f[i] = ((g[i] + g[i]) % MOD + f[i-2]) % MOD;
	}
	cout << f[n] << '\n';

	return 0;
}
