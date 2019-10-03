#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define MAX 1000001

int n, x, y;
bool visit[MAX];
int A[MAX], B[MAX], dist[MAX];
vector<int> graph[MAX];

void bfs()
{
	queue<int> que;
	for (int i=0; i<n+1; ++i) {
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
	fill(A, A+n+1, -1);
	fill(B, B+n+1, -1);
	while (1) {
		bfs();
		int flow = 0;
		for (int i=0; i<n+1; ++i)
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
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		graph[i].push_back(x-1);
		graph[i].push_back(y-1);
	}

	if (match() < n) {
		cout << "-1\n";
	} else {
		for (int i=0; i<n; ++i)
			cout << A[i]+1 << '\n';
	}

	return 0;
}
