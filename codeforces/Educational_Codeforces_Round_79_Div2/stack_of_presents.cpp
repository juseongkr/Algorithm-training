#include <iostream>
using namespace std;
#define MAX 100001

int a[MAX];

int main()
{
	int t, n, m, k;

	cin >> t;
	while (t--) {
		cin >> n >> m;
		fill(a, a+MAX, 0);
		for (int i=0; i<n; ++i) {
			cin >> k;
			a[k-1] = i;
		}
		
		int cur = -1;
		long long ans = 0;
		for (int i=0; i<m; ++i) {
			cin >> k;
			int pos = a[k-1];
			if (cur > pos) {
				ans++;
			} else {
				cur = pos;
				ans += 2 * (pos-i) + 1;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
