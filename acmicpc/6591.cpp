#include <iostream>
using namespace std;

int n, k;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	while (1) {
		cin >> n >> k;
		if (n == 0 && k == 0)
			break;

		k = min(k, n-k);

		int r = 1;
		long long ans = 1;
		while (r <= k) {
			ans *= n--;
			ans /= r++;
		}

		cout << ans << '\n';
	}

	return 0;
}
