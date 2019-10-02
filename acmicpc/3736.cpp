#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define MAX 10001

bool visit[MAX];
int A[MAX], B[MAX], dist[MAX];
vector<int> graph[MAX];
int n, m, u, v;

void bfs()
{
	queue<int> que;

	for (int i=0; i<MAX; ++i) {
		if (!visit[i]) {
			dist[i] = 0;
			que.push(i);
		} else {
			dist[i] = INT_MAX;
		}
	}

	while (!que.empty()) {
		int a = que.front();
		que.pop();
		for (int i=0; i<graph[a].size(); ++i) {
			int b = graph[a][i];
			if (B[b] != -1 && dist[B[b]] == INT_MAX) {
				dist[B[b]] = dist[a] + 1;
				que.push(B[b]);
			}
		}
	}
}

bool dfs(int a)
{
	for (int i=0; i<graph[a].size(); ++i) {
		int b = graph[a][i];
		if (B[b] == -1 || (dist[B[b]] == dist[a]+1 && dfs(B[b]))) {
			visit[a] = 1;
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int match()
{
	int ret = 0;
	fill(A, A+MAX, -1);
	fill(B, B+MAX, -1);
	while (1) {
		bfs();
		int flow = 0;
		for (int i=0; i<MAX; ++i)
			if (!visit[i] && dfs(i))
				flow++;
		if (flow == 0)
			break;
		ret += flow;
	}
	return ret;
}

int main()
{
	while (scanf("%d", &n) > 0) {
		for (int i=0; i<n; ++i) {
			scanf("%d: (%d)", &u, &m);
			for (int j=0; j<m; ++j) {
				scanf("%d", &v);
				graph[u].push_back(v-n);
			}
		}
		printf("%d\n", match());

		fill(visit, visit+MAX, 0);
		for (int i=0; i<n; ++i)
			graph[i].clear();
	}

	return 0;
}
