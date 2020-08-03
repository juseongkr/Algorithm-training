#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1000001

int n, m, x, y;
vector<int> graph[MAX];
int group[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (int k=1; k<=n; ++k) {
		if (!group[k])
			group[k] = k;

		queue<pair<int, int>> que;
		que.push({k, group[k]});

		while (!que.empty()) {
			auto [cur, grp] = que.front();
			que.pop();

			for (int i=0; i<graph[cur].size(); ++i) {
				int next = graph[cur][i];
				if (group[next] == grp) {
					cout << "IMPOSSIBLE\n";
					return 0;
				}
				if (!group[next]) {
					group[next] = -grp;
					que.push({next, -grp});
				}
			}
		}
	}
	cout << "POSSIBLE\n";

	return 0;
}
