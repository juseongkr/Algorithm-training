#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001

int n, m, c, x, y, z;
int cost[MAX], in[MAX];
vector<pair<int, int>> graph[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> c;
	for (int i=1; i<=n; ++i)
		cin >> cost[i];

	for (int i=0; i<c; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
		in[y]++;
	}

	queue<int> que;

	for (int i=1; i<=n; ++i)
		if (!in[i])
			que.push(i);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			auto [next, next_cost] = graph[cur][i];

			cost[next] = max(cost[next], cost[cur] + next_cost);
			if (--in[next] == 0)
				que.push(next);
		}
	}

	for (int i=1; i<=n; ++i)
		cout << cost[i] << '\n';

	return 0;
}
