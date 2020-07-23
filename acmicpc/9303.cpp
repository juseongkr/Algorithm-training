#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;
#define MAX 101
const double INF = -1e9;
typedef pair<double, int> pdi;

double z;
int T, n, s, e, m, x, y;
vector<pdi> graph[MAX];
double dist[MAX];
bool visit[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	for (int t=1; t<=T; ++t) {
		cin >> n >> s >> e >> m;
		for (int i=0; i<=n; ++i) {
			graph[i].clear();
			dist[i] = INF;
			visit[i] = 0;
		}

		for (int i=0; i<m; ++i) {
			cin >> x >> y >> z;
			graph[x].push_back({z, y});
			graph[y].push_back({z, x});
		}

		priority_queue<pdi> que;
		que.push({1, s});
		dist[s] = 1;

		while (!que.empty()) {
			auto [cost, cur] = que.top();
			que.pop();

			if (cur == e) {
				cout << fixed << setprecision(4) << "Case " << t << ": " << cost << '\n';
				break;
			}

			if (visit[cur])
				continue;
			visit[cur] = 1;

			for (int i=0; i<graph[cur].size(); ++i) {
				int next = graph[cur][i].second;
				double next_cost = graph[cur][i].first * cost;
				if (dist[next] < next_cost) {
					dist[next] = next_cost;
					que.push({next_cost, next});
				}
			}
		}
	}

	return 0;
}
