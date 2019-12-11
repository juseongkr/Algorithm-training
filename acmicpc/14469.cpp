#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, x, y;
	vector<pair<int, int>> vec;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		vec.push_back({x, y});
	}

	sort(vec.begin(), vec.end());

	int ans = 0;
	for (int i=0; i<n; ++i) {
		if (ans >= vec[i].first)
			ans += vec[i].second;
		else
			ans = vec[i].first + vec[i].second;
	}
	cout << ans << '\n';

	return 0;
}
