#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 300001
const int MOD = 1e9+7;

long long arr[MAX];

long long pow(long long a, long long b)
{
	long long ret = 1;
	while (b) {
		if (b % 2 != 0)
			ret = ret * a % MOD;
		a = a * a % MOD;
		b /= 2;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> arr[i];

	sort(arr, arr+n);

	long long ans = 0;
	for (int i=0; i<n; ++i) {
		long long temp = pow(2, i);
		ans += (arr[i] % MOD) * temp % MOD;
		temp = pow(2, n-i-1);
		ans -= (arr[i] % MOD) * temp % MOD;
		ans = ((ans % MOD) + MOD) % MOD;
	}
	cout << ans << '\n';

	return 0;
}
