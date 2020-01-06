#include <iostream>
using namespace std;
#define MAX 200001

int num[MAX], ans[MAX];

int main()
{
	int t, n, k;

	cin >> t;
	while (t--) {
		cin >> n;
		fill(num, num+MAX, 0);
		fill(ans, ans+MAX, 0);
		for (int i=0; i<n; ++i) {
			cin >> k;
			num[k] = i;
		}

		int mi = 1e9+7, mx = -1e9+7;
		for (int i=1; i<=n; ++i) {
			mi = min(mi, num[i]);
			mx = max(mx, num[i]);
			if (mx - mi + 1 == i)
				ans[i-1] = 1;
		}

		for (int i=0; i<n; ++i)
			cout << ans[i];
		cout << '\n';

	}

	return 0;
}
