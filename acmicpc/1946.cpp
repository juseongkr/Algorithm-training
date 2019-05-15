#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<pair<int, int>> vec;
	int t, n, a, b;

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; ++i) {
			cin >> a >> b;
			vec.push_back({a, b});
		}

		sort(vec.begin(), vec.end());

		int ans = 1;
		int prev = vec[0].second;
		for (int i=1; i<n; ++i) {
			int cur = vec[i].second;
			if (prev > cur) {
				prev = cur;
				ans++;
			}
		}
		cout << ans << '\n';
		vec.clear();
	}

	return 0;
}
