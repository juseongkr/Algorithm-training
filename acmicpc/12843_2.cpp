#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define MAX 2001

char c;
int n, m, t, x, y;
vector<int> vec, graph[MAX];
int A[MAX], B[MAX], visit[MAX], dist[MAX];

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
		for (int i=0; i<vec.size(); ++i)
			if (!visit[vec[i]] && dfs(vec[i]))
				flow++;
		if (flow == 0)
			break;
		ret += flow;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> t >> c;
		if (c == 'c')
			vec.push_back(t);
	}

	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	cout << n - match() << '\n';

	return 0;
}
