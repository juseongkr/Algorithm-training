#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<pair<int, int>> vec;
	int n, x, y;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		vec.push_back({y, x});
	}

	sort(vec.begin(), vec.end());

	int ans = vec[n-1].first - vec[n-1].second;
	for (int i=n-2; i>=0; i--)
		ans = min(ans, vec[i].first) - vec[i].second;

	if (ans < 0)
		cout << "-1\n";
	else
		cout << ans << '\n';

	return 0;
}
