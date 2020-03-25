#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define MAX 1002
const double INF = 1e17;
typedef pair<double, int> pdi;

double m;
int n, w, u, v;
int x[MAX], y[MAX];
double weight[MAX][MAX];
double dist[MAX];
vector<int> graph[MAX];

inline double di(int i, int j)
{
	double X = x[i]-x[j];
	double Y = y[i]-y[j];
	return sqrt(X*X + Y*Y);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> w >> m;
	for (int i=1; i<=n; ++i)
		cin >> x[i] >> y[i];

	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			weight[i][j] = INF;

	while (w--) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
		weight[u][v] = weight[v][u] = 0;
	}

	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			if (i == j)
				continue;
			double d = di(i, j);
			if (weight[i][j] == INF && d <= m) {
				graph[i].push_back(j);
				graph[j].push_back(i);
				weight[i][j] = weight[j][i] = d;
			}
		}
	}

	fill(dist, dist+MAX, INF);
	priority_queue<pdi, vector<pdi>, greater<pdi>> que;
	que.push({0, 1});
	dist[1] = 0;

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];
			if (dist[next] > dist[cur] + weight[cur][next]) {
				dist[next] = dist[cur] + weight[cur][next];
				que.push({dist[next], next});
			}
		}
	}
	cout << (long long)(dist[n] * 1000LL) << '\n';

	return 0;
}
