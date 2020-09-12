#include <iostream>
using namespace std;
#define MAX 100001

int T, n, m, k;
int num[MAX], psum[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> m >> k;
		for (int i=0; i<n; ++i)
			cin >> num[i];

		for (int i=1; i<n+m; ++i)
			psum[i] = psum[i-1] + num[(i-1)%n];

		int ans = 0;
		if (n == m && psum[n] < k) {
			ans++;
		} else {
			for (int i=m; i<n+m; ++i)
				if (psum[i] - psum[i-m] < k)
					ans++;
		}

		cout << ans << '\n';
	}

	return 0;
}
