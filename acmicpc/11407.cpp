#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define MAX 100
const int src = 202, sink = 203;

class MCMF {
public:
	vector<vector<int>> capa, flow, dist, graph;
	int len;

	MCMF(int n) : len(n+2)
	{
		capa.resize(len);
		flow.resize(len);
		dist.resize(len);
		graph.resize(len);
		for (int i=0; i<len; ++i) {
			capa[i].resize(len);
			flow[i].resize(len);
			dist[i].resize(len);
		}
	}

	// return cost, flow
	pair<int, int> mcmf(int src, int sink)
	{
		int min_cost = 0, max_flow = 0;
		vector<int> prev(len), d(len);
		vector<bool> inque(len);

		while (1) {
			for (int i=0; i<len; ++i) {
				d[i] = INT_MAX;
				prev[i] = -1;
			}

			queue<int> que;
			d[src] = 0;
			inque[src] = 1;
			que.push(src);

			while (!que.empty()) {
				int cur = que.front();
				que.pop();
				inque[cur] = 0;
				for (int i=0; i<graph[cur].size(); ++i) {
					int next = graph[cur][i];
					if (capa[cur][next] - flow[cur][next] > 0 && \
					d[next] > d[cur] + dist[cur][next]) {
						d[next] = d[cur] + dist[cur][next];
						prev[next] = cur;
						if (!inque[next]) {
							que.push(next);
							inque[next] = 1;
						}
					}
				}
			}
			if (prev[sink] == -1)
				break;

			int f = INT_MAX;
			for (int i=sink; i!=src; i=prev[i])
				f = min(f, capa[prev[i]][i] - flow[prev[i]][i]);

			for (int i=sink; i!=src; i=prev[i]) {
				min_cost += f * dist[prev[i]][i];
				flow[prev[i]][i] += f;
				flow[i][prev[i]] -= f;
			}
			max_flow += f;
		}

		return {min_cost, max_flow};
	}

	void add_edge(int s, int e, int c, int d)
	{
		graph[s].push_back(e);
		graph[e].push_back(s);
		capa[s][e] += c;
		dist[s][e] += d;
		dist[e][s] -= d;
	}
};

int a[MAX+1][MAX+1], b[MAX+1][MAX+1];

int main()
{
	int n, m, t;

	cin >> n >> m;
	MCMF mm = MCMF(2*MAX+4);
	for (int i=0; i<n; ++i) {
		cin >> t;
		mm.add_edge(MAX+i, sink, t, 0);
	}

	for (int i=0; i<m; ++i) {
		cin >> t;
		mm.add_edge(src, i, t, 0);
	}

	for (int i=0; i<m; ++i)
		for (int j=0; j<n; ++j)
			cin >> a[i][j];

	for (int i=0; i<m; ++i)
		for (int j=0; j<n; ++j)
			cin >> b[i][j];

	for (int i=0; i<m; ++i)
		for (int j=0; j<n; ++j)
			if (a[i][j])
				mm.add_edge(i, j+MAX, a[i][j], b[i][j]);

	auto ans = mm.mcmf(src, sink);
	cout << ans.second << '\n' << ans.first << '\n';

	return 0;
}
