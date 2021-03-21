#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, l, x, y, ans;
vector<pair<int, int>> vec;
priority_queue<int, vector<int>, greater<int>> que;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		vec.push_back({max(x, y), min(x, y)});
	}
	cin >> l;

	sort(vec.begin(), vec.end());

	for (int i=0; i<n; ++i) {
		auto [y, x] = vec[i];

		que.push(x);
		while (!que.empty() && que.top() < y - l)
			que.pop();

		ans = max(ans, (int)que.size());
	}

	cout << ans << '\n';

	return 0;
}
