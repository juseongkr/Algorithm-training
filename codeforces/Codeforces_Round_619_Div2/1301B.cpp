#include <iostream>
using namespace std;
#define MAX 100001
const int INF = 1e9+7;

int n, t;
int num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		fill(num, num+MAX, 0);
		for (int i=1; i<=n; ++i)
			cin >> num[i];

		int mx = -1, mi = INF;
		for (int i=1; i<=n; ++i) {
			if (num[i] != -1 && (num[i-1] == -1 || num[i+1] == -1)) {
				mx = max(mx, num[i]);
				mi = min(mi, num[i]);
			}
		}

		if (mx == -1) {
			cout << "0 0\n";
			continue;
		}

		int mid = (mx+mi)/2;
		for (int i=1; i<=n; ++i)
			if (num[i] == -1)
				num[i] = mid;

		int ans = 0;
		for (int i=1; i<n; ++i)
			ans = max(ans, abs(num[i] - num[i+1]));

		cout << ans << " " << mid << '\n';
	}

	return 0;
}
