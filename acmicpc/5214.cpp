#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 200002
const int INF = 1e9+7;

vector<int> graph[MAX];
int dist[MAX], visit[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k, m, t;

	cin >> n >> k >> m;
	int hyper = n+1;
	for (int i=0; i<m; ++i) {
		for (int j=0; j<k; ++j) {
			cin >> t;
			graph[t].push_back(hyper);
			graph[hyper].push_back(t);
		}
		hyper++;
	}

	queue<int> que;
	visit[1] = true;
	que.push(1);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		if (cur == n)
			break;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];

			if (visit[next])
				continue;

			visit[next] = 1;
			dist[next] = dist[cur] + 1;
			que.push(next);
		}
	}

	if (dist[n] == 0 && n != 1)
		cout << "-1\n";
	else
		cout << dist[n]/2 + 1 << '\n';

	return 0;
}
