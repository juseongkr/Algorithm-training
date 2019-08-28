#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

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

int conv(char c)
{
	if (c <= 'Z')
		return c - 'A';
	return c - 'a' + 26;
}

int main()
{
	int n, c;
	char a, b;

	cin >> n;
	NetworkFlow f = NetworkFlow(52);
	for (int i=0; i<n; ++i) {
		cin >> a >> b >> c;
		a = conv(a);
		b = conv(b);
		f.add_edge(a, b, c, 0);
		f.add_edge(b, a, c, 0);
	}
	cout << f.flow(conv('A'), conv('Z')) << '\n';

	return 0;
}
