#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 300001

vector<int> graph[MAX];
int dist[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, m, s, e, x, y;

	cin >> n >> m >> s >> e;
	for (int i=0; i<n; ++i) {
		graph[i].push_back(i+1);
		graph[i+1].push_back(i);
	}

	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	fill(dist, dist+MAX, -1);
	queue<int> que;
	dist[s] = 0;
	que.push(s);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];

			if (dist[next] == -1) {
				dist[next] = dist[cur] + 1;
				que.push(next);
			}
		}
	}
	cout << dist[e] << '\n';

	return 0;
}
