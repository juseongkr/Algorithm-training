#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 1001
typedef tuple<int, int, int> tp;
const int INF = 1e9+7;

int n, m, k, s, d, x, y, z;
vector<pair<int, int>> graph[MAX];
int t[30001], dist[MAX][MAX];
bool visit[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> k >> s >> d;
	s--;
	d--;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		x--;
		y--;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}

	for (int i=0; i<MAX; ++i)
		for (int j=0; j<MAX; ++j)
			dist[i][j] = INF;

	priority_queue<tp, vector<tp>, greater<tp>> que;
	dist[s][0] = 0;
	que.push({0, 0, s});

	while (!que.empty()) {
		auto [cost, cnt, cur] = que.top();
		que.pop();

		if (visit[cur][cnt])
			continue;
		visit[cur][cnt] = 1;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second;
			if (dist[next][cnt+1] > dist[cur][cnt] + next_cost && cnt+1 < MAX) {
				dist[next][cnt+1] = dist[cur][cnt] + next_cost;
				que.push({dist[next][cnt+1], cnt+1, next});
			}
		}
	}

	for (int i=1; i<=k; ++i)
		cin >> t[i];

	int sum = 0;
	for (int i=0; i<=k; ++i) {
		sum += t[i];
		int temp = INF;
		for (int j=0; j<n; ++j)
			temp = min(temp , dist[d][j] + sum * j);
		cout << temp << '\n';
	}

	return 0;
}
