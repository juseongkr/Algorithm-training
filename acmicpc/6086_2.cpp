#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 52
#define INF 1000000001

char a, b;
int n, t, S, E;
int c[MAX][MAX], f[MAX][MAX];
int work[MAX], level[MAX];
vector<int> graph[MAX];

bool bfs()
{
	fill(level, level+MAX, -1);
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
	if (level[E] == -1)
		return false;
	return true;
}

int dfs(int cur, int dest, int flow)
{
	if (cur == dest)
		return flow;

	for (int &i=work[cur]; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];

		if (level[next] == level[cur] + 1 && c[cur][next] - f[cur][next] > 0) {
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

int conv(char c)
{
	if (c <= 'Z')
		return c-'A';
	return c-'a'+26;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a >> b >> t;
		a = conv(a);
		b = conv(b);
		c[a][b] = c[b][a] += t;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	S = conv('A');
	E = conv('Z');

	int total = 0;
	while (bfs()) {
		fill(work, work+MAX, 0);
		while (1) {
			int flow = dfs(S, E, INF);
			if (flow == 0)
				break;
			total += flow;
		}
	}
	cout << total << '\n';

	return 0;
}
