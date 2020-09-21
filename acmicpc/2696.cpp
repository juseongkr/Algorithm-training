#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

int T, n, k;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		vector<int> ans;
		priority_queue<int> large;
		priority_queue<int, vector<int>, greater<int>> small;

		for (int i=0; i<n; ++i) {
			cin >> k;

			large.push(k);
			int tp = large.top();
			large.pop();
			small.push(tp);

			if (large.size() < small.size()) {
				tp = small.top();
				small.pop();
				large.push(tp);
			}

			if (i % 2 == 0)
				ans.push_back(large.top());
		}

		int cnt = 1;
		cout << ans.size() << '\n';
		for (int i=0; i<ans.size(); ++i, ++cnt) {
			cout << ans[i] << " ";
			if (cnt == 10) {
				cnt = 0;
				cout << '\n';
			}
		}
		cout << '\n';
	}

	return 0;
}
