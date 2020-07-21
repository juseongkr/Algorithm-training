#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define MAX 21
const int INF = 1e9+7;
typedef pair<int, int> pii;

int T, n, m, x, y, z;
vector<pii> graph[MAX];
int pre[MAX], dist[MAX];
bool visit[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	for (int t=1; t<=T; ++t) {
		cin >> m >> n;
		for (int i=0; i<n; ++i) {
			graph[i].clear();
			pre[i] = -1;
			visit[i] = 0;
			dist[i] = INF;
		}

		for (int i=0; i<m; ++i) {
			cin >> x >> y >> z;
			graph[x].push_back({y, z});
			graph[y].push_back({x, z});
		}

		priority_queue<pii, vector<pii>, greater<pii>> que;
		que.push({0, 0});
		dist[0] = 0;

		while (!que.empty()) {
			auto [cost, cur] = que.top();
			que.pop();

			if (visit[cur])
				continue;
			visit[cur] = 1;

			for (int i=0; i<graph[cur].size(); ++i) {
				int next = graph[cur][i].first;
				int next_cost = graph[cur][i].second + cost;

				if (dist[next] > next_cost) {
					pre[next] = cur;
					dist[next] = next_cost;
					que.push({next_cost, next});
				}
			}
		}

		cout << "Case #" << t << ": ";
		if (dist[n-1] == INF) {
			cout << "-1\n";
		} else {
			stack<int> st;
			for (int i=n-1; i!=-1; i=pre[i])
				st.push(i);

			while (!st.empty()) {
				cout << st.top() << " ";
				st.pop();
			}
			cout << '\n';
		}
	}

	return 0;
}
