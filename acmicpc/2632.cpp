#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1001

int n, m, k, p;
int a[MAX], b[MAX];
vector<int> x, y;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> p >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> a[i];

	for (int i=0; i<m; ++i)
		cin >> b[i];

	int l = 0, r = 0, sum = 0;
	while (l < n) {
		sum += a[r++];
		if (sum <= p) {
			x.push_back(sum);
		} else {
			l++;
			r = l;
			sum = 0;
		}
		r %= n;

		if ((l == 0 && r == 0) || l == r+1) {
			l++;
			r = l;
			sum = 0;
		}
	}

	l = 0, r = 0, sum = 0;
	while (l < m) {
		sum += b[r++];
		if (sum <= p) {
			y.push_back(sum);
		} else {
			l++;
			r = l;
			sum = 0;
		}
		r %= m;

		if ((l == 0 && r == 0) || l == r+1) {
			l++;
			r = l;
			sum = 0;
		}
	}

	x.push_back(0);
	y.push_back(0);

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	int ans = 0;
	for (int i=0; i<x.size(); ++i) {
		auto l = lower_bound(y.begin(), y.end(), p-x[i]) - y.begin();
		auto r = upper_bound(y.begin(), y.end(), p-x[i]) - y.begin();
		ans += r-l;
	}
	cout << ans << '\n';

	return 0;
}
