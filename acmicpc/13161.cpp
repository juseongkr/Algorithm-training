#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 502
#define INF 1000000001
const int S = MAX-2;
const int E = MAX-1;

int n;
int c[MAX][MAX], f[MAX][MAX];
int work[MAX], level[MAX];
bool visit[MAX];
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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			c[S][i] = INF;
			graph[S].push_back(i);
			graph[i].push_back(S);
		} else if (t == 2) {
			c[i][E] = INF;
			graph[E].push_back(i);
			graph[i].push_back(E);
		}
	}
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> c[i][j];
			if (i != j)
				graph[i].push_back(j);
		}
	}

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

	queue<int> que;
	visit[S] = true;
	que.push(S);
	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];
			if (!visit[next] && c[cur][next] - f[cur][next] > 0) {
				visit[next] = true;
				que.push(next);
			}
		}
	}

	for (int i=0; i<n; ++i)
		if (visit[i])
			cout << i+1 << " ";
	cout << '\n';

	for (int i=0; i<n; ++i)
		if (!visit[i])
			cout << i+1 << " ";
	cout << '\n';

	return 0;
}
