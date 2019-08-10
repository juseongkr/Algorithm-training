#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
const long long INF = 1e9+7;

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

	ll pa = -INF, pb = -INF, ans = 0;
	for (int i=0; i<n; ++i) {
		a = v[i].first;
		b = v[i].second;

		if (pa <= a && b <= pb)
			continue;
		else
			ans += b - a;

		if (a < pb)
			ans -= (pb - a);

		pa = a;
		pb = b;
	}
	cout << ans << '\n';

	return 0;
}
