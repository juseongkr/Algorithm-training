#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int t;
	long long n, m;

	cin >> t;
	while (t--) {
		cin >> n >> m;

		long long a = (n - m) / (m + 1);
		long long b = (n - m) % (m + 1);
		long long ans = n * (n + 1) / 2;

		ans -= (m - b + 1) * a * (a + 1) / 2;
		ans -= b * (a + 2) * (a + 1) / 2;

		cout << ans << '\n';
	}

	return 0;
}
