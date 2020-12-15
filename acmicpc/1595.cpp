#include <iostream>
#include <vector>
using namespace std;
#define MAX 10001

int x, y, z, far, ans;
vector<pair<int, int>> graph[MAX];
bool visit[MAX];

void dfs(int cur, int cost)
{
	if (visit[cur])
		return;
	visit[cur] = 1;

	if (ans < cost) {
		ans = cost;
		far = cur;
	}

	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i].first;
		int next_cost = graph[cur][i].second + cost;

		dfs(next, next_cost);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	while (cin >> x >> y >> z) {
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}

	dfs(1, 0);
	fill(visit, visit+MAX, 0);
	dfs(far, 0);

	cout << ans << '\n';

	return 0;
}
