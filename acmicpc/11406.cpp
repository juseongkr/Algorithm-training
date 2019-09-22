#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define MAX 100
const int src = 202, sink = 203;

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

	void add_edge(int u, int v, int c, int rev_c=0)
	{
		Edge forward, backward;
		forward.next = v;
		forward.capa = c;
		forward.inv = graph[v].size();
		backward.next = u;
		backward.capa = rev_c;
		backward.inv = graph[u].size();
		graph[u].push_back(forward);
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
	int n, m, t;

	cin >> n >> m;
	NetworkFlow f = NetworkFlow(2*MAX+4);
	for (int i=0; i<n; ++i) {
		cin >> t;
		f.add_edge(MAX+i, sink, t, 0);
	}

	for (int i=0; i<m; ++i) {
		cin >> t;
		f.add_edge(src, i, t, 0);
	}

	for (int i=0; i<m; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> t;
			f.add_edge(i, j+MAX, t, 0);
		}
	}

	cout << f.flow(src, sink) << '\n';

	return 0;
}
