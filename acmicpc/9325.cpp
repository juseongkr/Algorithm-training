#include <iostream>
using namespace std;

int main()
{
	int t, n, k, r, p;

	cin >> t;
	while (t--) {
		cin >> r >> n;
		int ans = r;
		for (int i=0; i<n; ++i) {
			cin >> k >> p;
			ans += k * p;
		}
		cout << ans << '\n';
	}

	return 0;
}
