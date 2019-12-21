#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	vector<pair<int, int>> vec;
	int n, x, y;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		vec.push_back({x - y, -(x + y)});
	}

	sort(vec.begin(), vec.end());

	int ans = 0, pos = -1;
	for (int i=0; i<vec.size(); ++i) {
		auto [a, b] = vec[i];
		if (-b > pos) {
			pos = -b;
			ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}
