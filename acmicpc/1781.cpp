#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, x, y;
vector<pair<int, int>> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		x--;
		vec.push_back({x, y});
	}

	sort(vec.begin(), vec.end());

	priority_queue<int> que;

	int ans = 0, cur = n-1;
	for (int i=n-1; i>=0; i--) {
		for (; cur>=0 && vec[cur].first == i; cur--)
			que.push(vec[cur].second);

		if (!que.empty()) {
			ans += que.top();
			que.pop();
		}
	}
	cout << ans << '\n';

	return 0;
}
