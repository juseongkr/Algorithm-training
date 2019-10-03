#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	priority_queue<int, vector<int>, greater<int>> x, y;
	int n, num, s, e, cnt = 0, ans = 0;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> num >> s >> e;
		x.push(s);
		y.push(e);
	}

	while (!x.empty()) {
		int a = x.top();
		int b = y.top();

		if (a < b) {
			x.pop();
			ans = max(ans, ++cnt);
		} else {
			y.pop();
			cnt--;
		}
	}
	cout << ans << '\n';

	return 0;
}
