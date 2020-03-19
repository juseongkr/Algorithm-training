#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define MAX 50001
const int INF = 1e9;
typedef pair<double, int> pd;

int n, f, x, y;
vector<pair<int, int>> vec;
vector<pd> graph[MAX];
double dist[MAX];
bool visit[MAX];

double getDist(int x1, int y1, int x2, int y2)
{
	auto x = (x1-x2) * (x1-x2);
	auto y = (y1-y2) * (y1-y2);
	return sqrt(x+y);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> f;
	vec.push_back({0, 0});
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		vec.push_back({x, y});
	}

	sort(vec.begin(), vec.end());

	for (int i=0; i<vec.size(); ++i) {
		for (int j=-2; j<=2; j++) {
			auto l = lower_bound(vec.begin(), vec.end(), make_pair(vec[i].first+j, -INF));
			auto r = upper_bound(vec.begin(), vec.end(), make_pair(vec[i].first+j, INF));

			auto x = lower_bound(l, r, make_pair(vec[i].first+j, vec[i].second-2));
			auto y = upper_bound(l, r, make_pair(vec[i].first+j, vec[i].second+2));

			for (auto k=x; k<y; ++k)
				graph[i].push_back({getDist(vec[i].first, vec[i].second, k->first, k->second), k - vec.begin()});
		}
	}

	fill(dist, dist+MAX, INF);
	priority_queue<pd, vector<pd>, greater<pd>> que;
	que.push({0.0, 0});
	dist[0] = 0;

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		if (visit[cur])
			continue;
		visit[cur] = 1;

		for (int i=0; i<graph[cur].size(); ++i) {
			double next_cost = graph[cur][i].first + cost;
			int next = graph[cur][i].second;

			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				que.push({next_cost, next});
			}
		}
	}

	double ans = INF;
	for (int i=0; i<vec.size(); ++i)
		if (vec[i].second == f)
			ans = min(ans, dist[i]);

	if (ans < INF)
		cout << round(ans) << '\n';
	else
		cout << "-1\n";

	return 0;
}
