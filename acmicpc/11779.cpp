#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001
typedef pair<int, int> pii;
const int INF = 1e9+7;

vector<pii> graph[MAX];
int n, m, a, b, c, s, e;
int dist[MAX], p[MAX], visit[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> a >> b >> c;
		graph[a].push_back({c, b});
	}
	cin >> s >> e;

	priority_queue<pii, vector<pii>, greater<pii>> que;
	fill(dist, dist+MAX, INF);
	dist[s] = 0;
	que.push({0, s});

	while (!que.empty()) {
		int cost = que.top().first;
		int cur = que.top().second;
		que.pop();

		if (visit[cur])
			continue;
		visit[cur] = 1;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next_cost = graph[cur][i].first;
			int next = graph[cur][i].second;

			if (dist[next] > next_cost + cost) {
				dist[next] = next_cost + cost;
				p[next] = cur;
				que.push({next_cost + cost, next});
			}
		}
	}
	cout << dist[e] << '\n';

	vector<int> v;
	for (int i=e; i!=0; i=p[i])
		v.push_back(i);

	cout << v.size() << '\n';
	for (int i=v.size()-1; i>=0; i--)
		cout << v[i] << " ";

	return 0;
}
