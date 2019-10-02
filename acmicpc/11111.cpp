#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define MAX 51
#define node(x, y) (x)*(MAX)+(y)
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int score[6][6] = { {10, 8, 7, 5, 0, 1},
			  {8, 6, 4, 3, 0, 1},
			  {7, 4, 3, 2, 0, 1},
			  {5, 3, 2, 2, 0, 1},
			  {0, 0, 0, 0, 0, 0},
			  {1, 1, 1, 1, 0, 0} };

class MCMF {
public:
	struct Edge {
		int v, c, d, rev;
		Edge() { }
		Edge(int x, int y, int z, int r) : v(x), rev(y), c(z), d(r) { }
	};
	int len;
	vector<vector<Edge>> graph;

	MCMF(int n) : len(n+2)
	{
		graph.resize(len);
	}

	// return cost, flow
	pair<int, int> mcmf(int src, int sink)
	{
		int min_cost = 0, max_flow = 0;
		vector<int> dist(len), prev(len), previdx(len);
		vector<bool> inque(len);

		while (1) {
			for (int i=0; i<len; ++i) {
				dist[i] = INT_MAX;
				prev[i] = previdx[i] = -1;
			}

			queue<int> que;
			inque[src] = true;
			dist[src] = 0;
			que.push(src);

			while (!que.empty()) {
				int cur = que.front();
				que.pop();
				inque[cur] = false;

				for (int i=0; i<graph[cur].size(); ++i) {
					int next = graph[cur][i].v;
					if (graph[cur][i].c && dist[next] > dist[cur] + graph[cur][i].d) {
						dist[next] = dist[cur] + graph[cur][i].d;
						prev[next] = cur;
						previdx[next] = i;
						if (!inque[next]) {
							inque[next] = true;
							que.push(next);
						}
					}
				}
			}
			if (prev[sink] == -1)
				break;

			int flow = INT_MAX;
			for (int i=sink; i!=src; i=prev[i])
				flow = min(flow, graph[prev[i]][previdx[i]].c);

			for (int i=sink; i!=src; i=prev[i]) {
				graph[prev[i]][previdx[i]].c -= flow;
				graph[i][graph[prev[i]][previdx[i]].rev].c += flow;
				min_cost += flow * graph[prev[i]][previdx[i]].d;
			}
			max_flow += flow;
		}
		return {min_cost, max_flow};
	}

	void add_edge(int u, int v, int c, int d)
	{
		graph[u].push_back(Edge(v, graph[v].size(), c, d));
		graph[v].push_back(Edge(u, graph[u].size()-1, 0, -d));
	}
};

int point[MAX][MAX];

int main()
{
	string s;
	int n, m;

	cin >> n >> m;
	MCMF mm = MCMF(MAX*MAX+2);
	int src = MAX*MAX+1, sink = MAX*MAX+2;
	for (int i=0; i<n; ++i) {
		cin >> s;
		for (int j=0; j<m; ++j)
			point[i][j] = s[j]-'A';
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			mm.add_edge(node(i, j), sink, 1, 0);
			if (i % 2 == j % 2) {
				mm.add_edge(src, node(i, j), 1, 0);
				for (int k=0; k<4; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						continue;

					int row = point[i][j];
					int col = point[nx][ny];

					mm.add_edge(node(i, j), node(nx, ny), 1, -score[row][col]);
				}
			}
		}
	}
	cout << -mm.mcmf(src, sink).first << '\n';

	return 0;
}
