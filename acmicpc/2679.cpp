#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001
const int INF = 1e9+7;

int T, n, m, x, y, z, sx, sy;
int c[MAX][MAX], f[MAX][MAX], pre[MAX], dp[MAX];
vector<int> graph[MAX];

int solve(int cur)
{
	if (cur == sy)
		return INF;

	if (~dp[cur])
		return dp[cur];

	dp[cur] = 0;
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		dp[cur] = max(dp[cur], min(solve(next), c[cur][next]));
	}

	return dp[cur];
}

void add_edge(int u, int v, int capa)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
	c[u][v] = capa;
}

int flow(int src, int sink)
{
	int total = 0;
	while (1) {
		fill(pre, pre+MAX, -1);
		queue<int> que;
		que.push(src);

		while (!que.empty()) {
			int cur = que.front();
			que.pop();
			if (cur == sink)
				break;
			for (int i=0; i<graph[cur].size(); ++i) {
				int next = graph[cur][i];
				if (pre[next] == -1 && c[cur][next] > f[cur][next]) {
					que.push(next);
					pre[next] = cur;
				}
			}
		}
		if (pre[sink] == -1)
			break;

		int min_val = INF;
		for (int i=sink; i!=src; i=pre[i])
			min_val = min(min_val, c[pre[i]][i] - f[pre[i]][i]);

		for (int i=sink; i!=src; i=pre[i]) {
			f[pre[i]][i] += min_val;
			f[i][pre[i]] -= min_val;
		}
		total += min_val;
	}
	return total;
}

int main()
{
	cin >> T;
	while (T--) {
		cin >> n >> m >> sx >> sy;
		for (int i=0; i<m; ++i) {
			cin >> x >> y >> z;
			add_edge(x, y, z);
		}
		memset(dp, -1, sizeof(dp));

		cout << fixed << setprecision(3) << flow(sx, sy) / (double)solve(sx) << '\n';

		for (int i=0; i<n; ++i) {
			graph[i].clear();
			fill(c[i], c[i]+MAX, 0);
			fill(f[i], f[i]+MAX, 0);
		}
	}

	return 0;
}
