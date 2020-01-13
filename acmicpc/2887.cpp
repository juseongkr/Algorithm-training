#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define ll long long 
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll> t3;

class UnionFind {
public:
	vector<ll> p;
	UnionFind(ll n) { p.resize(n+1, -1); }
	ll find(ll x)
	{
		if (p[x] < 0)
			return x;
		return p[x] = find(p[x]);
	}

	bool uni(ll x, ll y)
	{
		x = find(x);
		y = find(y);
		if (x == y)
			return false;
		if (p[x] < p[y])
			swap(x, y);
		p[y] += p[x];
		p[x] = y;
		return true;
	}
};

ll n, x, y, z;
vector<t4> vec;
vector<t3> point;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	UnionFind u = UnionFind(n);
	for (int i=0; i<n; ++i) {
		cin >> x >> y >> z;
		vec.push_back({x, y, z, i});
	}

	sort(vec.begin(), vec.end(), [](t4 &a, t4 &b) {
		return get<0>(a) < get<0>(b);
	});
	for (int i=1; i<n; ++i) {
		point.push_back({get<0>(vec[i]) - get<0>(vec[i-1]), get<3>(vec[i-1]), get<3>(vec[i])});
	}

	sort(vec.begin(), vec.end(), [](t4 &a, t4 &b) {
		return get<1>(a) < get<1>(b);
	});
	for (int i=1; i<n; ++i) {
		point.push_back({get<1>(vec[i]) - get<1>(vec[i-1]), get<3>(vec[i-1]), get<3>(vec[i])});
	}

	sort(vec.begin(), vec.end(), [](t4 &a, t4 &b) {
		return get<2>(a) < get<2>(b);
	});
	for (int i=1; i<n; ++i) {
		point.push_back({get<2>(vec[i]) - get<2>(vec[i-1]), get<3>(vec[i-1]), get<3>(vec[i])});
	}

	sort(point.begin(), point.end());

	ll ans = 0, cnt = 0;
	for (int i=0; i<point.size(); ++i) {
		auto [z, x, y] = point[i];
		if (u.uni(x, y)) {
			ans += z;
			if (++cnt == n-1)
				break;
		}
	}
	cout << ans << '\n';

	return 0;
}
