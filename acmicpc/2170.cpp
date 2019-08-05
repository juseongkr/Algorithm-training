#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
const int INF = 1e9+7;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<pair<ll, ll>> v;
	ll a, b;
	int n;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a >> b;
		v.push_back({a, b});
	}

	sort(v.begin(), v.end());

	ll px = -INF, py = -INF, ans = 0;
	for (int i=0; i<v.size(); ++i) {
		ll x = v[i].first;
		ll y = v[i].second;

		if (px <= x && y <= py)
			continue;
		else
			ans += y - x;

		if (x < py)
			ans -= (py - x);

		px = x;
		py = y;
	}
	cout << ans << '\n';

	return 0;
}
