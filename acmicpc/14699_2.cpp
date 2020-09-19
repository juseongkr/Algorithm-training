#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 5001

int n, m, x, y;
int high[MAX], in[MAX], dist[MAX];
vector<int> graph[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> high[i];

	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		x--;
		y--;
		if (high[x] > high[y]) {
			graph[x].push_back(y);
			in[y]++;
		} else {
			graph[y].push_back(x);
			in[x]++;
		}
	}

	queue<int> que;
	for (int i=0; i<n; ++i)
		if (!in[i])
			que.push(i);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];
			dist[next] = max(dist[next], dist[cur] + 1);
			if (--in[next] == 0)
				que.push(next);
		}
	}

	for (int i=0; i<n; ++i)
		cout << dist[i] + 1 << '\n';

	return 0;
}
