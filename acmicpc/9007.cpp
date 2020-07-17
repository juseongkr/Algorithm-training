#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1001
const long long INF = 1e16+7;

int T, n;
long long k;
long long a[MAX], b[MAX];
vector<long long> x, y;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> k >> n;
		for (int i=0; i<n; ++i)
			cin >> a[i];
		for (int i=0; i<n; ++i)
			cin >> b[i];
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
			x.push_back(a[i]+b[j]);

		for (int i=0; i<n; ++i)
			cin >> a[i];
		for (int i=0; i<n; ++i)
			cin >> b[i];
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
			y.push_back(a[i]+b[j]);

		sort(x.begin(), x.end());
		sort(y.begin(), y.end());

		long long ans = INF;
		for (int i=0; i<x.size(); ++i) {
			auto it = lower_bound(y.begin(), y.end(), k-x[i]);

			if (it != y.end()) {
				long long val = x[i] + *it;
				if (abs(ans-k) > abs(val-k))
					ans = val;
				if (abs(ans-k) == abs(val-k))
					ans = min(ans, val);
			}

			if (it != y.begin()) {
				long long val = x[i] + *--it;
				if (abs(ans-k) > abs(val-k))
					ans = val;
				if (abs(ans-k) == abs(val-k))
					ans = min(ans, val);
			}
		}

		cout << ans << '\n';
		x.clear();
		y.clear();
	}

	return 0;
}
