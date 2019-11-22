#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 101

vector<pair<int, int>> graph[MAX];
int need[MAX][MAX];
int in[MAX];

int main()
{
	int n, m, x, y, z;

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		graph[y].push_back({x, z});
		in[x]++;
	}

	queue<int> que;
	for (int i=1; i<=n; ++i) {
		if (!in[i]) {
			que.push(i);
			need[i][i] = 1;
		}
	}

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			auto [next, cost] = graph[cur][i];
			for (int j=1; j<=n; ++j)
				need[next][j] += need[cur][j] * cost;

			if (--in[next] == 0)
				que.push(next);
		}
	}

	for (int i=1; i<=n; ++i)
		if (need[n][i])
			cout << i << " " << need[n][i] << '\n';

	return 0;
}
