#include <iostream>
#include <climits>
#include <queue>
using namespace std;
#define MAX 802

int capa[MAX][MAX], flow[MAX][MAX], pre[MAX];
const int src = 1, sink = 2;

int main()
{
	int n, m, a, b, ans = 0;

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int u = i*2;
		int v = u+1;
		capa[u][v] = 1;
		capa[v][u] = 0;
	}

	for (int i=0; i<m; i++) {
		cin >> a >> b;
		a = (a-1)*2;
		b = (b-1)*2;
		capa[a+1][b] = capa[b+1][a] = 1;
	}

	while (1) {
		queue<int> que;
		fill(pre, pre+MAX, -1);
		que.push(src);
		while (!que.empty()) {
			int cur = que.front();
			que.pop();
			if (cur == sink)
				break;

			for (int next=0; next<MAX; ++next) {
				if (capa[cur][next] > flow[cur][next] && pre[next] == -1) {
					que.push(next);
					pre[next] = cur;
				}
			}
		}

		if (pre[sink] == -1)
			break;

		int min_flow = INT_MAX;
		for (int i=sink; i!=src; i=pre[i])
			min_flow = min(min_flow, capa[pre[i]][i] - flow[pre[i]][i]);

		for (int i=sink; i!=src; i=pre[i]) {
			flow[pre[i]][i] += min_flow;
			flow[i][pre[i]] -= min_flow;
		}
		ans += min_flow;
	}
	cout << ans << '\n';

	return 0;
}
