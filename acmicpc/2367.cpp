#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define N 201
#define D 101
#define MAX N+D+2
const int src = MAX-1, sink = MAX-2;

int n, k, d, p, t;
int c[MAX][MAX], f[MAX][MAX], pre[MAX];
vector<int> graph[MAX];

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

		int min_val = INT_MAX;
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
	cin >> n >> k >> d;
	for (int i=0; i<d; ++i) {
		cin >> p;
		add_edge(i+N, sink, p);
	}

	for (int i=0; i<n; ++i) {
		cin >> t;
		for (int j=0; j<t; ++j) {
			cin >> p;
			p--;
			add_edge(i, p+N, 1);
		}
		add_edge(src, i, k);
	}

	cout << flow(src, sink) << '\n';

	return 0;
}
