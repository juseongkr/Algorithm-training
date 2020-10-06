#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10001

int n, m, x, y;
vector<int> graph[MAX];
int cost[MAX], val[MAX], in[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=1; i<=n; ++i)
		cin >> val[i];

	while (m--) {
		cin >> x >> y;
		graph[x].push_back(y);
		in[y]++;
	}

	queue<int> que;

	for (int i=1; i<=n; ++i) {
		if (!in[i]) {
			que.push(i);
			cost[i] = val[i];
		}
	}

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];
			cost[next] = max(cost[next], cost[cur] + val[next]);
			if (--in[next] == 0)
				que.push(next);
		}
	}

	int ans = 0;
	for (int i=1; i<=n; ++i)
		ans = max(ans, cost[i]);

	cout << ans << '\n';

	return 0;
}
