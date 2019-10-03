#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9+7;

int n, m;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int in(int x, int y) { return 2*(x*m+y); }
int out(int x, int y) { return 2*(x*m+y)+1; }

class NetworkFlow {
public:
	int len;
	struct Edge{
		int next, inv, capa;
	};

	vector<vector<Edge>> graph;

	NetworkFlow(int n) : len(n)
	{
		graph.assign(len, vector<Edge>());
	}

	void add_edge(int u, int v, int c, int rev_c)
	{
		Edge foward, backward;
		foward.next = v;
		foward.capa = c;
		foward.inv = graph[v].size();
		backward.next = u;
		backward.capa = rev_c;
		backward.inv = graph[u].size();
		graph[u].push_back(foward);
		graph[v].push_back(backward);
	}

	int bfs(int src, int sink)
	{
		vector<bool> visit(len, false);
		vector<pair<int, int >> from(len, {-1, -1});
		queue<int> que;

		visit[src] = true;
		que.push(src);
		while (!que.empty()) {
			int cur = que.front();
			que.pop();

			for (int i=0; i<graph[cur].size(); ++i) {
				int next = graph[cur][i].next;
				if (!visit[next] && graph[cur][i].capa) {
					visit[next] = true;
					from[next] = {cur, i};
					que.push(next);
				}
			}
		}
		if (!visit[sink])
			return 0;

		int p = sink;
		int minflow = INF;
		while (from[p].first != -1) {
			minflow = min(minflow, graph[from[p].first][from[p].second].capa);
			p = from[p].first;
		}

		p = sink;
		while (from[p].first != -1) {
			Edge &e = graph[from[p].first][from[p].second];
			e.capa -= minflow;
			graph[e.next][e.inv].capa += minflow;
			p = from[p].first;
		}

		return minflow;
	}

	int flow(int src, int sink)
	{
		int total = 0;
		while (1) {
			int flow = bfs(src, sink);
			if (flow == 0)
				break;
			total += flow;
		}
		return total;
	}
};

int main()
{
	char map[101][101];
	int src, sink;

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'K')
				src = out(i, j);
			else if (map[i][j] == 'H')
				sink = in(i, j);
		}
	}

	NetworkFlow f = NetworkFlow(2*n*m);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (map[i][j] == '#')
				continue;

			int a = in(i, j);
			int b = out(i, j);
			f.add_edge(a, b, 1, 0);

			for (int k=0; k<4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == '#')
					continue;

				a = out(i, j);
				b = in(nx, ny);
				f.add_edge(a, b, INF, 0);
			}
		}
	}

	int ans = f.flow(src, sink);
	if (ans >= INF)
		cout << "-1\n";
	else
		cout << ans << '\n';

	return 0;
}
