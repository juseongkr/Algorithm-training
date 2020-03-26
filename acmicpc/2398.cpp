#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 1001
const int INF = 1e9+7;
typedef pair<int, int> pi;

int n, m, x, y, z;
vector<pi> graph[MAX];
bool visit[MAX];
int dist[MAX][3], path[MAX][3], pre[MAX][3], edge[3];

void dijkstra(int cur, int p)
{
	fill(visit, visit+MAX, 0);
	priority_queue<pi, vector<pi>, greater<pi>> que;
	dist[cur][p] = 0;
	que.push({0, cur});

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		if (visit[cur])
			continue;
		visit[cur] = 1;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second;

			if (dist[next][p] > dist[cur][p] + next_cost) {
				dist[next][p] = dist[cur][p] + next_cost;
				pre[next][p] = cur;
				que.push({dist[next][p], next});
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	memset(pre, -1, sizeof(pre));
	for (int i=0; i<n; ++i)
		for (int j=0; j<3; ++j)
			dist[i][j] = INF;

	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		x--;
		y--;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}

	for (int i=0; i<3; ++i) {
		cin >> edge[i];
		edge[i]--;
		dijkstra(edge[i], i);
	}

	int point = 0, mi = INF;
	for (int i=0; i<n; ++i) {
		if (mi > dist[i][0] + dist[i][1] + dist[i][2]) {
			mi = dist[i][0] + dist[i][1] + dist[i][2];
			point = i;
		}
	}

	vector<pi> vec;
	for (int i=0; i<3; ++i)
		for  (int j=point; j!=edge[i]; j=pre[j][i])
			vec.push_back({j+1, pre[j][i]+1});

	cout << mi << " " << vec.size() << '\n';
	for (int i=0; i<vec.size(); ++i)
		cout << vec[i].first << " " << vec[i].second << '\n';

	return 0;
}
