#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define MAX 101
typedef pair<int, int> pi;

int n, m, k, x, y, z;
int jewel[MAX], dist[MAX][(1 << 15)];
vector<pi> graph[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=0; i<k; ++i) {
		cin >> x;
		jewel[x] = i+1;
	}

	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}

	queue<pi> que;
	dist[1][0] = 1;
	que.push({1, 0});

	int ans = 0;
	while (!que.empty()) {
		auto [cur, bit] = que.front();
		que.pop();

		if (cur == 1)
			ans = max(ans, dist[cur][bit]);

		if (jewel[cur] && !(bit & (1 << jewel[cur]))) {
			int next_bit = bit | (1 << jewel[cur]);
			if (dist[cur][next_bit] < dist[cur][bit] + 1) {
				dist[cur][next_bit] = dist[cur][bit] + 1;
				que.push({cur, next_bit});
			}
		}

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second;

			if (dist[cur][bit] <= next_cost && dist[next][bit] < dist[cur][bit]) {
				dist[next][bit] = dist[cur][bit];
				que.push({next, bit});
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
