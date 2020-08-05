#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001
const int INF = 1e9+7;
typedef pair<int, int> pii;

int n, m, r, x, y, z;
vector<pii> graph[MAX];
int study[MAX];
bool visit[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	priority_queue<pii, vector<pii>, greater<pii>> que;

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> study[i];
		que.push({study[i], i});
	}

	cin >> r;
	for (int i=0; i<r; ++i) {
		cin >> x >> y >> z;
		graph[x-1].push_back({y-1, z});
	}

	int ans = -1, cnt = 0;
	while (!que.empty() && cnt < m) {
		auto [cost, cur] = que.top();
		que.pop();

		if (visit[cur])
			continue;
		visit[cur] = 1;
		cnt++;

		ans = max(ans, cost);
		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second;

			if (visit[next])
				continue;
			study[next] = max(0, study[next] - next_cost);
			que.push({study[next], next});
		}
	}

	cout << ans << '\n';

	return 0;
}
