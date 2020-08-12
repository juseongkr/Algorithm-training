#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 20001

int T, n, m, b;
int a[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i=0; i<n; ++i)
			cin >> a[i];

		sort(a, a+n);

		int ans = 0;
		for (int i=0; i<m; ++i) {
			cin >> b;
			int it = upper_bound(a, a+n, b) - a;
			ans += n - it;
		}
		cout << ans << '\n';
	}

	return 0;
}
