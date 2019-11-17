#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001

int in[MAX], ans[MAX];
vector<int> graph[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, m, u, v;

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> u >> v;
		graph[u].push_back(v);
		in[v]++;
	}

	queue<pair<int, int>> que;
	for (int i=1; i<=n; ++i)
		if (!in[i])
			que.push({i, 1});

	while (!que.empty()) {
		auto [cur, cnt] = que.front();
		ans[cur] = cnt;
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];

			if (--in[next] == 0)
				que.push({next, cnt+1});
		}
	}

	for (int i=1; i<=n; ++i)
		cout << ans[i] << " ";

	return 0;
}
