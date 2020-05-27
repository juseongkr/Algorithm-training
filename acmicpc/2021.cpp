#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001
const int INF = 1e9+7;

int n, l, u, s, e;
vector<int> graph[MAX*2];
int dist[MAX*2];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> l;
	for (int i=0; i<l; ++i) {
		while (1) {
			cin >> u;
			if (u == -1)
				break;
			graph[i+MAX].push_back(u);
			graph[u].push_back(i+MAX);
		}
	}
	cin >> s >> e;

	fill(dist, dist+MAX*2, INF);
	queue<int> que;
	dist[s] = 0;
	que.push(s);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];
			if (dist[next] > dist[cur] + 1) {
				dist[next] = dist[cur] + 1;
				que.push(next);
			}
		}
	}

	if (dist[e] == INF)
		cout << "-1\n";
	else
		cout << max(dist[e]/2-1, 0) << '\n';

	return 0;
}
