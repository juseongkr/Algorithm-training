#include <iostream>
#include <vector>
using namespace std;

int n, a, b;
vector<pair<int, int>> vec;

int main()
{
	cin >> n;
	vec.push_back({0, 0});
	for (int i=0; i<n; ++i) {
		cin >> a >> b;
		vec.push_back({a, b});
	}

	int idx = -1, ans = 0;
	for (int i=1; i<=n; ++i) {
		int l = max(vec[i-1].first, vec[i-1].second);
		int r = min(vec[i].first, vec[i].second);

		if (idx == l)
			ans += max(0, r-l);
		else
			ans += max(0, r-l+1);
		idx = r;
	}

	cout << ans << '\n';

	return 0;
}
