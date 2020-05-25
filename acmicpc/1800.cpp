#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001
const int INF = 1e9+7;
typedef pair<int, int> pi;

int n, p, k, x, y, z, mx;
vector<pi> graph[MAX];
bool visit[MAX][MAX];
int dist[MAX];

bool check(int mid)
{
	memset(visit, 0, sizeof(visit));

	queue<pi> que;
	visit[1][0] = 1;
	que.push({1, 0});

	while (!que.empty()) {
		auto [cur, con] = que.front();
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int cost = graph[cur][i].second;

			if (con < k && !visit[next][con+1]) {
				visit[next][con+1] = 1;
				que.push({next, con+1});
			}

			if (cost <= mid && !visit[next][con]) {
				visit[next][con] = 1;
				que.push({next, con});
			}
		}
	}

	for (int i=0; i<=k; ++i)
		if (visit[n][i])
			return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> p >> k;
	for (int i=0; i<p; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
		mx = max(mx, z);
	}

	fill(dist, dist+MAX, INF);
	queue<pi> que;
	dist[1] = 0;
	que.push({1, 0});

	while (!que.empty()) {
		auto [cur, cnt] = que.front();
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;

			if (dist[next] > dist[cur] + 1) {
				dist[next] = dist[cur] + 1;
				que.push({next, cnt+1});
			}
		}
	}

	if (dist[n] < k) {
		cout << "0\n";
		return 0;
	} else if (dist[n] == INF) {
		cout << "-1\n";
		return 0;
	}

	int l = 0, r = mx;
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid))
			r = mid-1;
		else
			l = mid+1;
	}
	cout << l << '\n';

	return 0;
}
