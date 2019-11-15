#include <iostream>
#include <functional>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001
typedef pair<int, int> pii;
const int INF = 1e9+7;

int dist[MAX], p[MAX];
vector<pii> graph[MAX];
int n, m, x, y, z;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		x--;
		y--;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}

	fill(dist, dist+MAX, INF);
	priority_queue<pii, vector<pii>, greater<pii>> que;
	que.push({0, 0});
	dist[0] = 0;

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second + cost;

			if (dist[next] > next_cost) {
				p[next] = cur;
				dist[next] = next_cost;
				que.push({next_cost, next});
			}
		}
	}

	cout << n-1 << '\n';
	for (int i=1; i<n; ++i)
		cout << i+1 << " " << p[i]+1 << '\n';

	return 0;
}
