#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int conv(char c)
{
	if (c <= 'Z')
		return c-'A';
	return c-'a'+26;
}

class Dinic {
public:
	int len, S, E;
	vector<vector<int>> graph, c, f;
	vector<int> work, level;

	Dinic(int n, int s, int e) : len(n), S(s), E(e)
	{
		work.resize(n, 0);
		level.resize(n, 0);
		graph.resize(n);
		for (auto &it : graph)
			it.resize(n, 0);
		c.resize(n);
		for (auto &it : c)
			it.resize(n, 0);
		f.resize(n);
		for (auto &it : f)
			it.resize(n, 0);
	}

	bool bfs()
	{
		for (int i=0; i<level.size(); ++i)
			level[i] = -1;
		level[S] = 0;

		queue<int> que;
		que.push(S);
		while (!que.empty()) {
			int cur = que.front();
			que.pop();
			for (int i=0; i<graph[cur].size(); ++i) {
				int next = graph[cur][i];
				if (level[next] == -1 && c[cur][next] - f[cur][next] > 0) {
					level[next] = level[cur] + 1;
					que.push(next);
				}
			}
		}
		return level[E] != -1;
	}
		
	int dfs(int cur, int dest, int flow)
	{
		if (cur == dest)
			return flow;

		for (int &i=work[cur]; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];
			if (level[next] == level[cur]+1 && c[cur][next] - f[cur][next] > 0) {
				int ret = dfs(next, dest, min(flow, c[cur][next] - f[cur][next]));
				if (ret > 0) {
					f[cur][next] += ret;
					f[next][cur] -= ret;
					return ret;
				}
			}
		}
		return 0;
	}

	int run()
	{
		int total = 0;
		while (bfs()) {
			for (int i=0; i<work.size(); ++i)
				work[i] = 0;
			while (1) {
				int flow = dfs(S, E, INT_MAX);
				if (flow == 0)
					break;
				total += flow;
			}
		}
		return total;
	}
};

int main()
{
	char a, b;
	int n, m, c;

	cin >> n;
	Dinic *d = new Dinic(53, conv('A'), conv('Z'));
	for (int i=0; i<n; ++i) {
		cin >> a >> b >> c;
		a = conv(a);
		b = conv(b);
		d->c[a][b] = d->c[b][a] += c;
		d->graph[a].push_back(b);
		d->graph[b].push_back(a);
	}

	cout << d->run() << '\n';

	return 0;
}
