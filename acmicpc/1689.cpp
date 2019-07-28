#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<pair<int, int>> vec;
	int n, a, b;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a >> b;
		vec.push_back({a, 1});
		vec.push_back({b, -1});
	}

	sort(vec.begin(), vec.end());

	int ans = 0, cnt = 0;
	for (int i=0; i<vec.size(); ++i) {
		cnt += vec[i].second;
		ans = max(ans, cnt);
	}
	cout << ans << '\n';

	return 0;
}
