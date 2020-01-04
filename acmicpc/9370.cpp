#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 2001
typedef pair<int, int> pii;
const int INF = 1e12+7;

int T, n, m, t, s, g, h, x, y, z;
vector<pii> graph[MAX];
vector<int> vec;
int dist[MAX];
bool visit[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		vec.clear();
		for (int i=0; i<MAX; ++i)
			graph[i].clear();
		cin >> n >> m >> t >> s >> g >> h;
		for (int i=0; i<m; ++i) {
			cin >> x >> y >> z;
			z *= 2;
			if ((x == g && y == h) || (x == h && y == g))
				z--;
			graph[x].push_back({y, z});
			graph[y].push_back({x, z});
		}

		for (int i=0; i<t; ++i) {
			cin >> x;
			vec.push_back(x);
		}

		fill(dist, dist+MAX, INF);
		fill(visit, visit+MAX, 0);
		priority_queue<pii, vector<pii>, greater<pii>> que;
		que.push({0, s});
		dist[s] = 0;

		while (!que.empty()) {
			auto [cost, cur] = que.top();
			que.pop();

			if (visit[cur])
				continue;

			visit[cur] = 1;
			for (int i=0; i<graph[cur].size(); ++i) {
				int next = graph[cur][i].first;
				int next_cost = graph[cur][i].second + cost;

				if (dist[next] > next_cost) {
					dist[next] = next_cost;
					que.push({next_cost, next});
				}
			}
		}

		sort(vec.begin(), vec.end());
		for (int i=0; i<vec.size(); ++i)
			if (dist[vec[i]] % 2 && dist[vec[i]] != INF)
				cout << vec[i] << ' ';
		cout << '\n';
	}

	return 0;
}
