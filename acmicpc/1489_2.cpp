#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define MAX 1001
const int src = 2002, sink = 2003;

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

int n;
int x[MAX], y[MAX];

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> x[i];

	for (int i=0; i<n; ++i)
		cin >> y[i];

	MCMF m(2*MAX+2);
	for (int i=0; i<n; ++i) {
		m.add_edge(src, i, 1, 0);
		for (int j=0; j<n; ++j) {
			if (x[i] > y[j])
				m.add_edge(i, j+n, 1, -2);
			else if (x[i] < y[j])
				m.add_edge(i, j+n, 1, 0);
			else
				m.add_edge(i, j+n, 1, -1);
		}
		m.add_edge(i+n, sink, 1, 0);
	}

	cout << -m.mcmf(src, sink).first << '\n';

	return 0;
}
