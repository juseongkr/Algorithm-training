#include <iostream>
using namespace std;

int main()
{
	int t, n, k, p, ans;

	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n >> k;
		for (int i=0; i<n; ++i) {
			cin >> p;
			ans += p/k;
		}
		cout << ans << '\n';
	}

	return 0;
}
