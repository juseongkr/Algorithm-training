#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, x, y;
priority_queue<int> que;
vector<pair<int, int>> t;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		t.push_back({x, y});
	}

	sort(t.begin(), t.end());

	que.push(-t[0].second);
	for (int i=1; i<n; ++i) {
		if (-que.top() <= t[i].first)
			que.pop();
		que.push(-t[i].second);
	}
	cout << que.size() << '\n';

	return 0;
}
