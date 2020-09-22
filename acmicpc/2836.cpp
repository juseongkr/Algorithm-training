#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, x, y, mx;
vector<pair<int, int>> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		if (x > y)
			vec.push_back({y, x});
	}

	sort(vec.begin(), vec.end());

	long long prev = vec[0].second;
	long long len = vec[0].second - vec[0].first;
	for (int i=1; i<vec.size(); ++i) {
		auto [x, y] = vec[i];
		if (prev < x) {
			len += y - x;
			prev = y;
		} else {
			if (prev < y) {
				len += y - prev;
				prev = y;
			}
		}
	}

	cout << len * 2 + m << '\n';

	return 0;
}
