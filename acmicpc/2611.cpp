#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define MAX 1001

int n, m, x, y, k;
vector<pair<int, int>> graph[MAX];
int dist[MAX], pre[MAX];

int main()
{
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> k;
		graph[x].push_back({y, k});
	}

	priority_queue<pair<int, int>> que;
	fill(dist, dist+MAX, -1e9+7);
	dist[1] = 0;
	que.push({0, 1});

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second + cost;

			if (dist[next] < next_cost) {
				dist[next] = next_cost;
				pre[next] = cur;
				if (next != 1)
					que.push({next_cost, next});
			}
		}
	}
	stack<int> st;
	cout << dist[1] << '\n';
	for (int i=pre[1]; i!=1; i=pre[i])
		st.push(i);

	cout << "1 ";
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << "1\n";

	return 0;
}
