#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, x, y;
vector<pair<int, int>> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		vec.push_back({x, 1});
		vec.push_back({y, -1});
	}

	sort(vec.begin(), vec.end());

	int ans = 0, cnt = 0;
	for (int i=0; i<2*n; ++i) {
		auto [x, y] = vec[i];
		cnt += y;
		ans = max(ans, cnt);
	}

	cout << ans << '\n';

	return 0;
}
