#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define M 50
#define MAX M*M+2
#define node(i, j) i*M+j
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int src = MAX-2, sink = MAX-1;
const int INF = 1e9+7;

int t, n, m;
int map[M+1][M+1];
vector<int> graph[MAX];
int c[MAX][MAX], f[MAX][MAX], pre[MAX];

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
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		int sum = 0;
		cin >> n >> m;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				cin >> map[i][j];
				sum += map[i][j];
			}
		}

		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				int cur = node(i, j);
				if (i % 2 == j % 2) {
					add_edge(src, cur, map[i][j]);
					for (int k=0; k<4; ++k) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						int next = node(nx, ny);

						if (nx < 0 || nx >= n || ny < 0 || ny >= m)
							continue;

						add_edge(cur, next, INF);
					}
				} else {
					add_edge(cur, sink, map[i][j]);
				}
			}
		}

		cout << sum - flow(src, sink) << '\n';

		for (int i=0; i<MAX; ++i)
			graph[i].clear();
		memset(c, 0, sizeof(c));
		memset(f, 0, sizeof(f));
	}

	return 0;
}
