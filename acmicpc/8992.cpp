#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

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

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int t, n, m, x1, x2, y1, y2, c;

	cin >> t;
	while (t--) {
		cin >> n >> m;

		MCMF mm = MCMF(n+m+2);
		vector<tuple<int, int, int, int>> px(n+1), py(m+1);
		int src = n+m+1, sink = n+m+2;
		
		for (int i=1; i<=n; ++i) {
			cin >> x1 >> y1 >> x2 >> y2 >> c;
			if (x1 > x2)
				swap(x1, x2);
			px[i] = {x1, x2, y1, c};
		}

		for (int i=1; i<=m; ++i) {
			cin >> x1 >> y1 >> x2 >> y2 >> c;
			if (y1 > y2)
				swap(y1, y2);
			py[i] = {y1, y2, x1, c};
		}

		for (int i=1; i<=n; ++i) {
			mm.add_edge(src, i, 1, 0);
			for (int j=1; j<=m; ++j) {
				if (get<0>(px[i]) <= get<2>(py[j]) && \
				get<2>(py[j]) <= get<1>(px[i]) && \
				get<0>(py[j]) <= get<2>(px[i]) && \
				get<2>(px[i]) <= get<1>(py[j]))
					mm.add_edge(i, j+n, 1, -get<3>(px[i]) * get<3>(py[j]));
			}
		}

		for (int i=1; i<=m; ++i)
			mm.add_edge(i+n, sink, 1, 0);

		auto ans = mm.mcmf(src, sink);
		cout << ans.second << " " << -ans.first << '\n';
	}

	return 0;
}
