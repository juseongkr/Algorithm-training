#include <iostream>
using namespace std;

int T, n, m, x;
int num[1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> m;
		fill(num, num+1001, 0);
		for (int i=0; i<n; ++i) {
			cin >> x;
			num[x]++;
		}

		int ans = -1;
		for (int i=0; i<m; ++i) {
			cin >> x;
			if (num[x])
				ans = x;
		}

		if (ans != -1) {
			cout << "YES\n1 " << ans << '\n';
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}
