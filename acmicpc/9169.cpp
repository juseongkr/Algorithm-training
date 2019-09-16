#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define MAX 304
const int src = 301, sink = 302;

int num[MAX];

class NetworkFlow {
public:
	int len;
	struct Edge{
		int next, inv = 0, capa = 0;
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
		forward.capa += c;
		forward.inv = graph[v].size();
		backward.next = u;
		backward.capa += rev_c;
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
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, m, x, y;

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		fill(num, num+MAX, 0);
		NetworkFlow f = NetworkFlow(MAX);
		for (int i=1; i<=n; ++i) {
			cin >> x;
			num[i] = x;
			if (x == 0)
				f.add_edge(src, i, 1);
			else
				f.add_edge(i, sink, 1);
		}

		for (int i=1; i<=m; ++i) {
			cin >> x >> y;
			if (num[x] && !num[y]) {
				f.add_edge(y, x, 1);
			} else if (!num[x] && num[y]) {
				f.add_edge(x, y, 1);
			} else {
				f.add_edge(x, y, 1);
				f.add_edge(y, x, 1);
			}
		}
		cout << f.flow(src, sink) << '\n';
	}

	return 0;
}
