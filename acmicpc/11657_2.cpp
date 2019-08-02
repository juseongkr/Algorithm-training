#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 501
const int INF = 1e9+7;

vector<pair<int, int>> graph[MAX];
int dist[MAX], visit[MAX], cnt[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, a, b, c;

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
	}

	fill(dist, dist+MAX, INF);
	queue<int> que;
	que.push(1);
	visit[1] = 1;
	dist[1] = 0;
	
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		visit[cur] = 0;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int cost = graph[cur][i].second;

			if (dist[next] > dist[cur] + cost) {
				dist[next] = dist[cur] + cost;
				if (!visit[next]) {
					visit[next] = 1;
					que.push(next);
					cnt[next]++;
					if (cnt[next] >= n) {
						cout << "-1\n";
						return 0;
					}
				}
			}
		}
	}
	for (int i=2; i<=n; ++i) {
		if (dist[i] == INF)
			cout << "-1\n";
		else
			cout << dist[i] << "\n";
	}

	return 0;
}
