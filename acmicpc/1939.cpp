#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001

vector<pair<int, int>> graph[MAX];
int visit[MAX];
int n, m, a, b, c, s, e, max_cost, ans;

bool bfs(int cost)
{
	queue<int> que;
	que.push(s);
	visit[s] = 1;

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		if (cur == e)
			return true;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second;
			if (!visit[next] && cost <= next_cost) {
				visit[next] = 1;
				que.push(next);
			}
		}
	}
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
		max_cost = max(max_cost, c);
	}
	cin >> s >> e;

	int l = 0, r = max_cost;
	while (l <= r) {
		fill(visit, visit+MAX, 0);
		int mid = (l + r) / 2;
		if (bfs(mid)) {
			ans = max(ans, mid);
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans << '\n';

	return 0;
}
