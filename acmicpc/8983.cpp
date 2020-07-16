#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, l, x, y;
vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> m >> n >> l;
	for (int i=0; i<m; ++i) {
		cin >> x;
		vec.push_back(x);
	}

	sort(vec.begin(), vec.end());

	int ans = 0;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		if (y <= l) {
			auto left = lower_bound(vec.begin(), vec.end(), x-l+y) - vec.begin();
			auto right = upper_bound(vec.begin(), vec.end(), x+l-y) - vec.begin();

			if (right > left)
				ans++;

		}
	}
	cout << ans << '\n';

	return 0;
}
