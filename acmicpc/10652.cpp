#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define MAX 40001

int B, E, P, n, m, x, y;
vector<int> graph[MAX];

vector<int> bfs(int k)
{
	vector<int> dist(n+1, -1);
	queue<int> que;
	que.push(k);
	dist[k] = 0;

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];

			if (dist[next] != -1)
				continue;

			dist[next] = dist[cur] + 1;
			que.push(next);
		}
	}

	return dist;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> B >> E >> P >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	auto d1 = bfs(1);
	auto d2 = bfs(2);
	auto d3 = bfs(n);

	long long ans = LLONG_MAX;
	for (int i=1; i<=n; ++i) {
		long long ret = B * d1[i] + E * d2[i] + P * d3[i];
		ans = min(ans, ret);
	}

	cout << ans << '\n';

	return 0;
}
