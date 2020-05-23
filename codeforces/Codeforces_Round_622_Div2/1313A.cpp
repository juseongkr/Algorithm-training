#include <iostream>
#include <algorithm>
using namespace std;

int T;
int a[3];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a+3);

		int ans = 0;

		if (a[0] > 0) {
			a[0]--;
			ans++;
		}

		if (a[1] > 0) {
			a[1]--;
			ans++;
		}

		if (a[2] > 0) {
			a[2]--;
			ans++;
		}

		if (a[0] && a[2]) {
			a[0]--;
			a[2]--;
			ans++;
		}

		if (a[1] && a[2]) { 
			a[1]--;
			a[2]--;
			ans++;
		}

		if (a[0] && a[1]) {
			a[0]--;
			a[1]--;
			ans++;
		}

		if (a[0] && a[1] && a[2]) {
			ans++;
		}

		cout << ans << '\n';
	}

	return 0;
}
