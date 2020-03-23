#include <iostream>
using namespace std;
#define MAX 101

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int q, n, m;
	long long t[MAX], l[MAX], h[MAX];

	cin >> q;
	while (q--) {
		cin >> n >> m;
		t[0] = l[0] = h[0] = 0;
		for (int i=1; i<=n; ++i)
			cin >> t[i] >> l[i] >> h[i];

		bool flag = true;
		long long pos_min = m, pos_max = m;
		for (int i=1; i<=n; ++i) {
			int s = t[i] - t[i-1];
			pos_min -= s;
			pos_max += s;
			if (pos_min > h[i] || pos_max < l[i]) {
				flag = false;
				break;
			} else {
				pos_min = max(pos_min, l[i]);
				pos_max = min(pos_max, h[i]);
			}
		}

		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
