#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10001
const int INF = 1e9+7;
typedef pair<int, int> pii;

int t, n, d, c, x, y, z;
vector<pii> graph[MAX];
bool visit[MAX];
int dist[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> d >> c;
		c--;
		for (int i=0; i<MAX; ++i)
			graph[i].clear();

		for (int i=0; i<d; ++i) {
			cin >> x >> y >> z;
			graph[y-1].push_back({z, x-1});
		}

		fill(visit, visit+MAX, 0);
		fill(dist, dist+MAX, INF);
		priority_queue<pii, vector<pii>, greater<pii>> que;
		que.push({0, c});
		dist[c] = 0;

		int cnt = 0, time = 0;
		while (!que.empty()) {
			auto [cost, cur] = que.top();
			que.pop();

			if (visit[cur])
				continue;
			visit[cur] = 1;

			cnt++;
			time = dist[cur];
			for (int i=0; i<graph[cur].size(); ++i) {
				int next_cost = graph[cur][i].first + cost;
				int next = graph[cur][i].second;

				if (dist[next] > next_cost) {
					dist[next] = next_cost;
					que.push({next_cost, next});
				}
			}
		}
		cout << cnt << " " << time << '\n';
	}

	return 0;
}
