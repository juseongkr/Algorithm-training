#include <iostream>
using namespace std;
#define MAX 1000001

long long num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	long long t;

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		fill(num, num+n, 0);
		for (int i=0; i<n; ++i)
			cin >> num[i];

		int ans = 0;
		for (int i=0; i<m; ++i) {
			cin >> t;
			int l = 0, r = n-1;
			while (l <= r) {
				int mid = (l+r)/2;
				if (num[mid] == t) {
					ans++;
					break;
				} else if (num[mid] < t) {
					l = mid+1;
				} else {
					r = mid-1;
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
