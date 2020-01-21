#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define M 50
#define MAX 102

const int src = 100, sink = 101;
int n, m, k, a, b;
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

		for (int i=sink; i!=src; i=pre[i]) {
			f[pre[i]][i]++;
			f[i][pre[i]]--;
		}
		total++;
	}
	return total;
}

void check(int src, int sink)
{
	fill(pre, pre+MAX, -1);
	queue<int> que;
	que.push(src);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		if (src == sink)
			break;
		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];
			if (cur < src || (cur == src && next < sink))
				continue;

			if (pre[next] == -1 && c[cur][next] > f[cur][next]) {
				que.push(next);
				pre[next] = cur;
			}
		}
	}
	if (pre[sink] == -1)
		return;

	f[src][sink] = f[sink][src] = 0;
	for (int i=sink; i!=src; i=pre[i]) {
		f[pre[i]][i]++;
		f[i][pre[i]]--;
	}
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> k;
		a += k;
		add_edge(src, i, k);
		for (int j=0; j<m; ++j)
			add_edge(i, j+M, 1);
	}

	for (int j=0; j<m; ++j) {
		cin >> k;
		b += k;
		add_edge(j+M, sink, k);
	}

	if (a != b || flow(src, sink) < a) {
		cout << "-1\n";
		return 0;
	}

	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (f[i][j+M])
				check(i, j+M);

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j)
			cout << f[i][j+M];
		cout << '\n';
	}

	return 0;
}
