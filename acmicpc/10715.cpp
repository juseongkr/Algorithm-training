#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001
const long long INF = 1e18+7;
typedef pair<long long, int> pii;

long long total;
int n, m, c, x, y, z;
vector<pii> graph[MAX];
long long dist[MAX];
bool visit[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	cin >> n >> m >> c;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
		total += z;
	}

	fill(dist, dist+MAX, INF);
	priority_queue<pii, vector<pii>, greater<pii>> que;
	que.push({0, 1});
	dist[1] = 0;

	long long ans = total;
	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		if (visit[cur])
			continue;
		visit[cur] = 1;
		
		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			long long next_cost = graph[cur][i].second;

			if (visit[next])
				total -= next_cost;
		}

		ans = min(ans, c * dist[cur] + total);

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			long long next_cost = graph[cur][i].second + cost;

			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				que.push({next_cost, next});
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
