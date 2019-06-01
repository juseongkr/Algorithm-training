#include <iostream>
#include <queue>
using namespace std;

int main()
{
	priority_queue<pair<int, int>> que;
	int n, a, b;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a >> b;
		que.push({b, a});
	}
	
	int ans = que.top().first;
	while (!que.empty()) {
		auto t = que.top();
		que.pop();
		if (t.first > ans) {
			ans -= t.second;
		} else {
			ans = t.first;
			ans -= t.second;
		}
	}

	if (ans >= 0)
		cout << ans << '\n';
	else
		cout << "-1\n";

	return 0;
}
