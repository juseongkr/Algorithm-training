#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int> que;
	vector<pair<int, int>> val;
	vector<int> bag;
	int n, k, w, p, b, idx = 0;
	long long ans = 0;

	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> w >> p;
		val.push_back({w, p});
	}

	for (int i=0; i<k; ++i) {
		cin >> b;
		bag.push_back(b);
	}

	sort(bag.begin(), bag.end());
	sort(val.begin(), val.end());

	for (int i=0; i<k; ++i) {
		while (bag[i] >= val[idx].first && idx < n)
			que.push(val[idx++].second);
		
		if (!que.empty()) {
			ans += que.top();
			que.pop();
		}
	}

	cout << ans << '\n';

	return 0;
}
