#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10001

int main()
{
	vector<pair<int, int>> vec;
	priority_queue<int, vector<int>, greater<int>> que;
	int n, d, p;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> p >> d;
		vec.push_back({d, p});
	}

	sort(vec.begin(), vec.end());

	int ans = 0;
	for (int i=0; i<n; ++i) {
		ans += vec[i].second;
		que.push(vec[i].second);
		if (que.size() > vec[i].first) {
			ans -= que.top();
			que.pop();
		}
	}
	cout << ans << '\n';

	return 0;
}
