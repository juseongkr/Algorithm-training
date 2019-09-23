#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<pair<int, int>> vp;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) { return make_pair(a.second, a.first) < make_pair(b.second, b.first); }

int dist(pair<int, int> a, pair<int, int> b) { return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second); }

int find_point(vp &v, int s, int e)
{
	int ret = -1;
	for (int i=s; i<=e-1; ++i) {
		for (int j=i+1; j<=e; ++j) {
			int d = dist(v[i], v[j]);
			if (ret == -1 || ret > d)
				ret = d;
		}
	}
	return ret;
}

int solve(vp &X, vp &Y, int s, int e)
{
	if (e-s+1 <= 3)
		return find_point(X, s, e);

	int m = (s+e)/2;
	auto mid = X[m];

	vp new_X, new_Y;
	for (auto p : Y) {
		if (p <= mid)
			new_X.push_back(p);
		else
			new_Y.push_back(p);
	}
	
	int left = solve(X, new_X, s, m);
	int right = solve(X, new_Y, m+1, e);
	int ans = min(left, right);

	vp Z;
	for (auto p : Y) {
		int d = p.first - mid.first;
		if (d*d < ans)
			Z.push_back(p);
	}

	int len = Z.size();
	for (int i=0; i<len-1; ++i) {
		for (int j=i+1; j<len; ++j) {
			int t = Z[j].second - Z[i].second;
			if (t*t < ans) {
				int d = dist(Z[i], Z[j]);
				ans = min(ans, d);
			} else {
				break;
			}
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x, y;

	cin >> n;
	vp X, Y;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		X.push_back({x, y});
		Y.push_back({x, y});
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end(), cmp);

	cout << solve(X, Y, 0, n-1) << '\n';

	return 0;
}
