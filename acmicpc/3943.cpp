#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n, ans;

	cin >> t;
	while (t--) {
		cin >> n;
		ans = n;

		while (n != 1) {
			if (n % 2 == 0)
				n /= 2;
			else
				n = n * 3 + 1;
			ans = max(ans, n);
		}
		cout << ans << '\n';
	}

	return 0;
}
