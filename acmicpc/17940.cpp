#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 1001
const int INF = 1e9+7;
typedef tuple<int, int, int> ti;

int n, m;
bool type[MAX], visit[MAX];
int map[MAX][MAX];
int dist[MAX], trans[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> type[i];

	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cin >> map[i][j];

	for (int i=1; i<n; ++i)
		dist[i] = trans[i] = INF;

	priority_queue<ti, vector<ti>, greater<ti>> que;
	que.push({0, 0, 0});

	while (!que.empty()) {
		auto [cnt, cost, cur] = que.top();
		que.pop();

		if (visit[cur])
			continue;
		visit[cur] = 1;

		if (cur == m) {
			cout << cnt << ' ' << cost << '\n';
			return 0;
		}

		for (int next=0; next<n; ++next) {
			if (map[cur][next]) {
				int next_cnt = type[cur] == type[next] ? cnt : cnt+1;
				int next_cost = map[cur][next] + cost;

				if (trans[next] > next_cnt || dist[next] > next_cost) {
					dist[next] = next_cost;
					trans[next] = next_cnt;
					que.push({next_cnt, next_cost, next});
				}
			}
		}
	}

	return 0;
}
