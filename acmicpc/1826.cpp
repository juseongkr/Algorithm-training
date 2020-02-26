#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, a, b, l, p;
vector<pair<int, int>> vec;

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a >> b;
		vec.push_back({a, b});
	}
	cin >> l >> p;

	sort(vec.begin(), vec.end());

	int idx = 0, ans = 0;
	priority_queue<int> que;

	while (p < l) {
		while (vec[idx].first <= p && idx < n)
			que.push(vec[idx++].second);

		if (que.empty())
			break;

		ans++;
		p += que.top();
		que.pop();
	}
	if (p < l)
		cout << "-1\n";
	else
		cout << ans << '\n';

	return 0;
}
