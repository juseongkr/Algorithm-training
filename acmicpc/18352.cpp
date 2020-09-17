#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 300001

int n, m, k, x, u, v;
vector<int> graph[MAX];
bool visit[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> k >> x;
	while (m--) {
		cin >> u >> v;
		graph[u].push_back(v);
	}

	queue<pair<int, int>> que;
	que.push({x, 0});
	visit[x] = 1;

	vector<int> ans;
	while (!que.empty()) {
		auto [cur, cost] = que.front();
		que.pop();

		if (cost == k) {
			ans.push_back(cur);
		}

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];
			
			if (!visit[next]) {
				visit[next] = 1;
				que.push({next, cost+1});
			}
		}
	}

	if (ans.size()) {
		sort(ans.begin(), ans.end());
		for (int i=0; i<ans.size(); ++i)
			cout << ans[i] << '\n';
	} else {
		cout << "-1\n";
	}

	return 0;
}
