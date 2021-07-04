#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define MAX 48
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m;
char map[MAX][MAX];

int in(int x, int y) { return 2*(x*m+y); }
int out(int x, int y) { return 2*(x*m+y)+1; }
int type(int x, int y)
{
	if ((x+y) % 2 == 0)
		return 2;
	else if (x % 2 == 0)
		return 3;
	return 1;
}

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
		int minflow = INT_MAX;
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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	NetworkFlow f = NetworkFlow(2*n*m+2);
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	int src = 2*n*m;
	int sink = 2*n*m+1;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (map[i][j] != '.')
				continue;
			int u = in(i, j);
			int v = out(i, j);
			int t = type(i, j);

			f.add_edge(u, v, 1, 0);
			if (t == 1)
				f.add_edge(src, u, 1, 0);
			else if (t == 3)
				f.add_edge(v, sink, 1, 0);

			for (int k=0; k<4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m)
					continue;

				if (map[nx][ny] == '.' && type(i, j)+1 == type(nx, ny)) {
					int next = in(nx, ny);
					f.add_edge(v, next, 1, 0);
				}
			}
		}
	}
	cout << f.flow(src, sink) << '\n';
	
	return 0;
}
