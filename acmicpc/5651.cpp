#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;
#define MAX 301

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int capa[MAX][MAX], flow[MAX][MAX], prev[MAX];
	int t, n, m, a, b, c, src, sink;

	cin >> t;
	while (t--) {
		vector<int> graph[MAX];
		vector<pair<int, int>> li;
		for (int i=0; i<MAX; ++i)
			for (int j=0; j<MAX; ++j)
				capa[i][j] = flow[i][j] = 0;
		cin >> n >> m;
		src = 1, sink = n;
		for (int i=0; i<m; ++i) {
			cin >> a >> b >> c;
			graph[a].push_back(b);
			graph[b].push_back(a);
			capa[a][b] += c;
			li.push_back({a, b});
		}

		int total = 0;
		while (1) {
			fill(prev, prev+MAX, -1);
			queue<int> que;
			que.push(src);

			while (!que.empty()) {
				int cur = que.front();
				que.pop();

				if (cur == sink)
					break;

				for (int i=0; i<graph[cur].size(); ++i) {
					int next = graph[cur][i];
					if (prev[next] == -1 && capa[cur][next] > flow[cur][next]) {
						que.push(next);
						prev[next] = cur;
					}
				}
			}
			if (prev[sink] == -1)
				break;

			int min_flow = INT_MAX;
			for (int i=sink; i!=src; i=prev[i])
				min_flow = min(min_flow, capa[prev[i]][i] - flow[prev[i]][i]);

			for (int i=sink; i!=src; i=prev[i]) {
				flow[prev[i]][i] += min_flow;
				flow[i][prev[i]] -= min_flow;
			}
			total += min_flow;
		}

		int ans = 0;
		for (int i=0; i<li.size(); ++i) {
			fill(prev, prev+MAX, -1);
			src = li[i].first;
			sink = li[i].second;
			queue<int> que;
			que.push(src);

			while (!que.empty()) {
				int cur = que.front();
				que.pop();

				for (int i=0; i<graph[cur].size(); ++i) {
					int next = graph[cur][i];
					if (prev[next] == -1 && capa[cur][next] > flow[cur][next]) {
						que.push(next);
						prev[next] = cur;
					}
				}
			}
			if (prev[sink] == -1)
				ans++;
		}
		cout << ans << '\n';
	}

	return 0;
}
