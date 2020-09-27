#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MOD 40000

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
		vec.push_back({x, y});
	}

	sort(vec.begin(), vec.end(), [](auto x, auto y) {
		if (!y.first && !y.second)
			return false;
		if (!x.first && !x.second)
			return true;
		return x.first * y.second > y.first * x.second;
	});

	int ans = 0;
	for (const auto v : vec) {
		ans += (v.first * ans) % MOD + v.second;
		ans %= MOD;
	}
	cout << ans << '\n';

	return 0;
}
