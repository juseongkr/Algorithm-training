#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1004
const int INF = 1e9+7;

int v, m, idx;
double sx, sy, ex, ey;
double x[MAX], y[MAX];
vector<int> graph[MAX];
int dist[MAX];

inline double d(int x1, int y1, int x2, int y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main()
{
	cin >> v >> m;
	while (cin >> x[idx] >> y[idx]) {
		for (int i=0; i<idx; ++i) {
			if (d(x[i], y[i], x[idx], y[idx]) <= v * v * m * m * 3600) {
				graph[i].push_back(idx);
				graph[idx].push_back(i);
			}
		}
		idx++;
	}

	fill(dist, dist+MAX, INF);
	queue<int> que;
	dist[0] = 0;
	que.push(0);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		if (cur == 1) {
			cout << "Yes, visiting " << dist[1]-1 << " other holes.\n";
			return 0;
		}

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];
			if (dist[next] > dist[cur] + 1) {
				dist[next] = dist[cur] + 1;
				que.push(next);
			}
		}
	}
	cout << "No.\n";

	return 0;
}
