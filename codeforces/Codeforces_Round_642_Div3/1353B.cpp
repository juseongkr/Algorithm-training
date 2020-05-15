#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 31

int T, n, k;
int a[MAX], b[MAX];
bool visit[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> k;
		for (int i=0; i<n; ++i)
			cin >> a[i];

		for (int i=0; i<n; ++i)
			cin >> b[i];

		sort(a, a+n);
		sort(b, b+n);
		fill(visit, visit+n, 0);

		for (int i=0; i<n; i++) {
			for (int j=n-1; j>=0; j--) {
				if (a[i] < b[j] && !visit[j] && k > 0) {
					swap(a[i], b[j]);
					visit[j] = 1;
					k--;
					break;
				}
			}
		}

		int ans = 0;
		for (int i=0; i<n; ++i)
			ans += a[i];

		cout << ans << '\n';
	}

	return 0;
}
