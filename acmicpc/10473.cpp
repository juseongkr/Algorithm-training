#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;
#define MAX 101
const double INF = 1e9;
typedef pair<double, int> pi;

int n;
double x, y, sx, sy, ex, ey;
vector<pair<double, double>> vec;
double dist[MAX];
bool visit[MAX];

inline double dis(int x, int y)
{
	double X = (vec[x].first - vec[y].first);
	double Y = (vec[x].second - vec[y].second);
	return sqrt(X*X + Y*Y);
}

int main()
{
	cin >> sx >> sy >> ex >> ey >> n;
	vec.push_back({sx, sy});

	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		vec.push_back({x, y});
	}

	vec.push_back({ex, ey});

	fill(dist, dist+MAX, INF);
	priority_queue<pi, vector<pi>, greater<pi>> que;
	que.push({0, 0});
	dist[0] = 0;

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		if (visit[cur])
			continue;
		visit[cur] = 1;

		for (int next=1; next<vec.size(); ++next) {
			double walk = dis(cur, next) / 5.0;
			double fly = 2.0 + abs(dis(cur, next)-50.0) / 5.0;
			double next_cost = cur == 0 ? walk : min(walk, fly) + cost;

			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				que.push({next_cost, next});
			}
		}
	}

	cout << setprecision(10) << dist[vec.size()-1] << '\n';

	return 0;
}
