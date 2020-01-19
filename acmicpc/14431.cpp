#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define MAX 4001
#define P_MAX 10000
typedef pair<int, int> pii;
const int INF = 1e9+7;

int sx, sy, ex, ey, n, x, y;
vector<pii> point, graph[MAX];
bool visit[MAX], check[P_MAX], prime[P_MAX];
int dist[MAX];

inline int distance(pii x, pii y)
{
	int X = (x.first - y.first);
	int Y = (x.second - y.second);
	return sqrt(X*X + Y*Y);
}

int main()
{
	cin >> sx >> sy >> ex >> ey >> n;
	point.push_back({sx, sy});
	point.push_back({ex, ey});
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		point.push_back({x, y});
	}

	fill(check+2, check+P_MAX, 1);
	for (int i=2; i<P_MAX; ++i) {
		if (check[i])
			prime[i] = 1;
		for (int j=i; j<P_MAX; j+=i)
			check[j] = 0;
	}

	for (int i=0; i<point.size()-1; ++i) {
		for (int j=i+1; j<point.size(); ++j) {
			int d = distance(point[i], point[j]);
			if (prime[d]) {
				graph[i].push_back({d, j});
				graph[j].push_back({d, i});
			}
		}
	}

	fill(dist, dist+MAX, INF);
	priority_queue<pii, vector<pii>, greater<pii>> que;
	que.push({0, 0});
	dist[0] = 0;

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		if (visit[cur])
			continue;
		visit[cur] = 1;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next_cost = graph[cur][i].first + cost;
			int next = graph[cur][i].second;

			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				que.push({next_cost, next});
			}
		}
	}

	if (dist[1] != INF)
		cout << dist[1] << '\n';
	else
		cout << "-1\n";

	return 0;
}
