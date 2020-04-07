#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define MAX 304
const int src = 301, sink = 302;
const int INF = 1e8+7;

int n, m, x, y;
int c[MAX][MAX], f[MAX][MAX], pre[MAX];
vector<int> graph[MAX];

void add_edge(int u, int v, int capa)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
	c[u][v] = c[v][u] = capa;
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
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		for (int i=0; i<n; ++i) {
			cin >> x;
			if (x == 0)
				add_edge(src, i, 1);
			else
				add_edge(i, sink, 1);
		}

		for (int i=0; i<m; ++i) {
			cin >> x >> y;
			x--;
			y--;
			add_edge(x, y, 1);
		}
		cout << flow(src, sink) << '\n';
		memset(f, 0, sizeof(f));
		memset(c, 0, sizeof(c));
		memset(pre, 0, sizeof(pre));
	}

	return 0;
}
