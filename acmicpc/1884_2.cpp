#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 101
typedef tuple<int, int, int> tp;
const int INF = 1e9+7;

int k, n, r, s, d, l, t;
vector<tp> graph[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> k >> n >> r;
	for (int i=0; i<r; ++i) {
		cin >> s >> d >> l >> t;
		graph[s].push_back({l, t, d});
	}

	priority_queue<tp, vector<tp>, greater<tp>> que;
	que.push({0, 0, 1});

	while (!que.empty()) {
		auto [cost, time, cur] = que.top();
		que.pop();

		if (cur == n) {
			cout << cost << '\n';
			return 0;
		}

		for (int i=0; i<graph[cur].size(); ++i) {
			auto [l, t, next] = graph[cur][i];

			if (time + t <= k)
				que.push({cost + l, time + t, next});
		}
	}

	cout << "-1\n";

	return 0;
}
