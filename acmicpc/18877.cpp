#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
const ll INF = 1e18+7;

ll x, y;
int n, m;
vector<pair<ll, ll>> vec;

bool check(ll mid)
{
	int cnt = 0;
	ll cur = -INF;
	for (int i=0; i<vec.size(); ++i) {
		auto [left, right] = vec[i];
		for (; max(cur + mid, left)<=right; cur=max(cur + mid, left))
			if (++cnt == n)
				return true;
	}

	return cnt == n;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		vec.push_back({x, y});
	}

	sort(vec.begin(), vec.end());

	ll l = 0, r = INF;
	while (l <= r) {
		ll mid = (l+r)/2;
		if (check(mid))
			l = mid+1;
		else
			r = mid-1;
	}
	cout << r << '\n';

	return 0;
}
