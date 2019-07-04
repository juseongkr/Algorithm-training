#include <iostream>
using namespace std;
#define MAX 100001
#define MOD 9901

int l[MAX], r[MAX], x[MAX];

int main()
{
	int n;

	cin >> n;
	l[1] = r[1] = x[1] = 1;
	for (int i=2; i<=n; ++i) {
		x[i] = (l[i-1] + r[i-1] + x[i-1]) % MOD;
		l[i] = (r[i-1] + x[i-1]) % MOD;
		r[i] = (l[i-1] + x[i-1]) % MOD;
	}
	cout << (l[n] + r[n] + x[n]) % MOD << '\n';

	return 0;
}
