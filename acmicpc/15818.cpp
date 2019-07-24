#include <iostream>
using namespace std;

int main()
{
	long long n, m, k, ans;

	cin >> n >> m >> k;
	ans = k % m;
	for (int i=1; i<n; ++i) {
		cin >> k;
		ans = ((ans % m) * (k % m)) % m;
	}
	cout << ans << '\n';

	return 0;
}
