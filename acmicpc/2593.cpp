#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define MAX 100001
const int INF = 1e9+7;

int n, m, x, y, u, v;
vector<int> graph[MAX*2];
int dist[MAX*2], pre[MAX*2];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=1; i<=m; ++i)  {
		cin >> x >> y;
		for (int j=x; j<=n; j+=y) {
			graph[i+MAX].push_back(j);
			graph[j].push_back(i+MAX);
		}
	}
	cin >> u >> v;

	fill(dist, dist+MAX*2, INF);
	queue<int> que;
	dist[u] = 0;
	que.push(u);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];

			if (dist[next] > dist[cur]) {
				dist[next] = dist[cur] + 1;
				pre[next] = cur;
				que.push(next);
			}
		}
	}

	if (dist[v] == INF) {
		cout << "-1\n";
	} else {
		cout << dist[v] / 2 << '\n';
		stack<int> st;
		for (int i=pre[v]; i!=0; i=pre[pre[i]])
			st.push(i-MAX);

		while (!st.empty()) {
			cout << st.top() << '\n';
			st.pop();
		}
	}

	return 0;
}
