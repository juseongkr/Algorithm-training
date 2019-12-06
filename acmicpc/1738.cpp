#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define MAX 101
const int INF = 1e9+7;

vector<pair<int, int>> graph[MAX];
vector<int> path[MAX];
int dist[MAX], p[MAX];
bool visit[MAX];

int main()
{
	int n, m, x, y, z;

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		graph[x-1].push_back({y-1, -z});
		path[y-1].push_back(x-1);
	}

	queue<int> que;
	visit[n-1] = 1;
	que.push(n-1);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		for (int i=0; i<path[cur].size(); ++i)  {
			int next = path[cur][i];
			if (!visit[next]) {
				visit[next] = 1;
				que.push(next);
			}
		}
	}

	fill(dist, dist+MAX, INF);
	fill(p, p+MAX, -1);

	dist[0] = 0;

	for (int k=0; k<n; ++k) {
		for (int i=0; i<n; ++i) {
			for (int j=0; j<graph[i].size(); ++j) {
				int next = graph[i][j].first;
				int cost = graph[i][j].second + dist[i];

				if (dist[i] != INF && dist[next] > cost) {
					if (k == n-1 && visit[next]) {
						cout << "-1\n";
						return 0;
					}

					dist[next] = cost;
					p[next] = i;
				}
			}
		}
	} 

	if (dist[n-1] == INF) {
		cout << "-1\n";
	} else {
		stack<int> st;
		for (int i=n-1; i!=0; i=p[i])
			st.push(i+1);
		cout << "1 ";
		while (!st.empty()) {
			cout << st.top() << " ";
			st.pop();
		}
	}

	return 0;
}
