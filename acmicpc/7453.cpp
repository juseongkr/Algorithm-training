#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 4001

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> ab, cd;
	int a[MAX], b[MAX], c[MAX], d[MAX];
	int n;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			ab.push_back(a[i] + b[j]);
			cd.push_back(c[i] + d[j]);
		}
	}

	sort(cd.begin(), cd.end());

	long long ans = 0;
	for (int i=0; i<cd.size(); ++i) {
		int l = 0 , r = cd.size();
		while (l < r) {
			int mid = (l + r) / 2;

			if (ab[i] + cd[mid] < 0)
				l = mid + 1;
			else
				r = mid;
		}
		int low = r;

		l = 0, r = cd.size();
		while (l < r) {
			int mid = (l + r) / 2;

			if (ab[i] + cd[mid] <= 0)
				l = mid + 1;
			else
				r = mid;
		}
		int high = r;

		ans += high - low;
	}

	cout << ans << '\n';

	return 0;
}
