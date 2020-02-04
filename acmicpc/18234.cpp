#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, t, x, y;
vector<pair<int, int>> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> t;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		vec.push_back({y, x});
	}

	sort(vec.begin(), vec.end());

	long long ans = 0;
	for (int i=0; i<n; ++i) {
		auto [add, base] = vec[i];
		ans += base + 1LL * add * (t-n+i);
	}
	cout << ans << '\n';
	
	return 0;
}
