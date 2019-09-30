#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001

int a, b, n, m, u, v;
vector<int> graph[MAX];
int dist[MAX];

int main()
{
	cin >> a >> b >> n >> m;
	fill(dist, dist+MAX, -1);
	for (int i=0; i<m; ++i) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	queue<int> que;
	dist[a] = 0;
	que.push(a);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		if (cur == b) {
			cout << dist[cur] << '\n';
			return 0;
		}

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];
			if (dist[next] == -1) {
				dist[next] = dist[cur] + 1;
				que.push(next);
			}
		}
	}
	cout << "-1\n";

	return 0;
}
