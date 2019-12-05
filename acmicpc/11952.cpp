#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define MAX 100001
typedef pair<long long, long long> pll;

int n, m, k, s, p, q, x, y, t;
bool zombie[MAX], danger[MAX], visit[MAX];
int X[MAX], Y[MAX];
long long dist[MAX];
vector<int> graph[MAX];
queue<int> qu;

void bfs()
{
	for (int i=0; i<s; ++i) {
		int sz = qu.size();
		for (int j=0; j<sz; ++j) {
			int cur = qu.front();
			qu.pop();
			for (int k=0; k<graph[cur].size(); ++k) {
				int next = graph[cur][k];
				if (!danger[next]) {
					danger[next] = 1;
					qu.push(next);
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> k >> s >> p >> q;
	for (int i=0; i<k; ++i) {
		cin >> t;
		qu.push(t);
		zombie[t] = danger[t] = 1;
	}

	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	bfs();

	priority_queue<pll, vector<pll>, greater<pll>> que;
	fill(dist, dist+MAX, LLONG_MAX);
	dist[1] = 0;
	que.push({0, 1});

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		if (visit[cur])
			continue;
		visit[cur] = 1;

		for (int i=0; i<graph[cur].size(); ++i) {
			long long next = graph[cur][i];
			long long next_cost = dist[cur];
			if (zombie[next])
				continue;

			if (next != n)
				next_cost += (danger[next] ? q : p);
		
			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				que.push({next_cost, next});
			}
		}
	}

	cout << dist[n] << '\n';

	return 0;
}
