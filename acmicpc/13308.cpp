#include <iostream>
#include <functional>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
#define MAX 2501
const int INF = 1e18+7;
typedef pair<int, int> pii;
typedef tuple<long long, int, int> tp;

int p[MAX];
int n, m, x, y, z;
bool visit[MAX][MAX];
vector<pii> graph[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=1; i<=n; ++i)
		cin >> p[i];

	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}

	priority_queue<tp, vector<tp>, greater<tp>> que;
	que.push({0, 1, p[1]});
	long long ans = 0;

	while (!que.empty()) {
		auto [dist, cur, cost] = que.top();
		que.pop();

		if (visit[cur][cost])
			continue;
		visit[cur][cost] = 1;

		if (cur == n) {
			ans = dist;
			break;
		}

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second;

			que.push({cost * next_cost + dist, next, min(cost, p[next])});
		}
	}
	cout << ans << '\n';

	return 0;
}
