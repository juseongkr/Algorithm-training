#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
#define MAX 251
const int INF = 1e9+7;
typedef pair<int, int> pii;

int n, m, x, y, z;
vector<int> graph[MAX];
int weight[MAX][MAX], p[MAX];

int dijkstra()
{
	fill(p, p+MAX, 0);
	vector<bool> visit(MAX, 0);
	vector<int> dist(MAX, INF);
	priority_queue<pii, vector<pii>, greater<pii>> que;
	que.push({0, 1});
	dist[1] = 0;

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		if (visit[cur])
			continue;
		visit[cur] = 1;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];
			int next_cost = weight[cur][next] + cost;

			if (dist[next] > next_cost) {
				p[next] = cur;
				dist[next] = next_cost;
				que.push({next_cost, next});
			}
		}
	}
	return dist[n];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back(y);
		graph[y].push_back(x);
		weight[x][y] = weight[y][x] = z;
	}

	int before = dijkstra();

	vector<int> path;
	for (int i=n; i!=0; i=p[i])
		path.push_back(i);

	int after = 0;
	for (int i=0; i<path.size()-1; ++i) {
		int u = path[i];
		int v = path[i+1];
		weight[u][v] *= 2;
		weight[v][u] *= 2;
		after = max(after, dijkstra());
		weight[u][v] /= 2;
		weight[v][u] /= 2;
	}
	cout << after - before << '\n';

	return 0;
}
