#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define MAX 2001

int n, c, m, x, y, z;
vector<tuple<int, int, int>> vec;
int loaded[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> c >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		vec.push_back({y, x, z});
	}

	sort(vec.begin(), vec.end());

	int ans = 0;
	for (int i=0; i<m; ++i) {
		int mx = 0;
		auto [e, s, v] = vec[i];
		for (int j=s; j<e; ++j)
			mx = max(mx, loaded[j]);

		int more = min(v, c - mx);
		ans += more;

		for (int j=s; j<e; ++j)
			loaded[j] += more;
	}

	cout << ans << '\n';

	return 0;
}
