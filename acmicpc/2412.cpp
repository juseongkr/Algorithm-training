#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 50001

int n, T, x, y;
vector<pair<int, int>> vec;
int dist[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> T;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		vec.push_back({x, y});
	}
	vec.push_back({0, 0});

	sort(vec.begin(), vec.end());

	queue<int> que;
	dist[0] = 1;
	que.push(0);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		if (vec[cur].second == T) {
			cout << dist[cur]-1 << '\n';
			return 0;
		}

		for (int i=-2; i<=2; ++i) {
			for (int j=-2; j<=2; ++j) {
				auto k = make_pair(vec[cur].first + i, vec[cur].second + j);
				int it = lower_bound(vec.begin(), vec.end(), k) - vec.begin();
				if (!dist[it] && vec[it] == k) {
					dist[it] = dist[cur] + 1;
					que.push(it);
				}
			}
		}
	}
	cout << "-1\n";

	return 0;
}
