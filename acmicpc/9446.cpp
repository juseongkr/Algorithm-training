#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10001
typedef pair<long long, long long> pl;

priority_queue<pl> que;
vector<pl> graph[MAX];
long long cost[MAX];
int n, m, x, y, a;
bool visit[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=1; i<=n; ++i) {
		cin >> cost[i];
		que.push({-cost[i], i});
	}

	for (int i=0; i<m; ++i) {
		cin >> a >> x >> y;
		graph[x].push_back({y, a});
		graph[y].push_back({x, a});
	}

	while (!que.empty()) {
		auto [val, x] = que.top();
		que.pop();

		if (visit[x])
			continue;
		visit[x] = 1;

		for (int i=0; i<graph[x].size(); ++i) {
			auto [y, a] = graph[x][i];

			if (cost[a] > cost[x] + cost[y]) {
				cost[a] = cost[x] + cost[y];
				que.push({-cost[a], a});
			}
		}
	}

	cout << cost[1] << '\n';

	return 0;
}
