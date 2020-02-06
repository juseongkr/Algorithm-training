#include <iostream>
using namespace std;
#define MAX 1001

int t, n, m, k;

int main()
{
	cin >> t;
	while (t--) {
		cin >> n >> m;
		int ans = 0;
		for (int i=0; i<n; ++i) {
			cin >> k;
			ans += k * 2;
		}

		if (n == 2 || n != m) {
			cout << "-1\n";
		} else {
			cout << ans << '\n';
			for (int i=1; i<n; ++i)
				cout << i << ' ' << i+1 << '\n';
			cout << n << ' ' << 1 << '\n';
		}
	}

	return 0;
}
