#include <iostream>
#include <vector>
using namespace std;

int n, m, l, x, y, ans;
vector<pair<int, int>> vec;

void func(int x, int y, int k, int t)
{
	int ret = 0;
	for (int i=0; i<m; ++i) {
		if (x <= vec[i].first && vec[i].first <= x + k && \
			y <= vec[i].second && vec[i].second <= y + t)
			ret++;
		ans = max(ans, ret);
	}
}

int main()
{
	cin >> n >> l >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		vec.push_back({x, y});
	}

	for (int i=0; i<m; ++i)
		for (int j=0; j<m; ++j)
			for (int k=1; k<l/2; ++k)
				func(vec[i].first, vec[j].second, k, l/2-k);

	cout << ans << '\n';

	return 0;
}
