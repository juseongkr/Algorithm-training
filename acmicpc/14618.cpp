#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define MAX 5001
const int INF = 1e9+7;
typedef pair<int, int> pii;

vector<pii> graph[MAX];
int dist[MAX];

int main()
{
	map<int, char> dict;
	int n, m, jin, k, t, x, y, z;

	cin >> n >> m >> jin >> k;
	for (int i=0; i<k; ++i) {
		cin >> t;
		dict[t] = 'A';
	}

	for (int i=0; i<k; ++i) {
		cin >> t;
		dict[t] = 'B';
	}

	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}

	fill(dist, dist+MAX, INF);
	priority_queue<pii, vector<pii>, greater<pii>> que;
	dist[jin] = 0;
	que.push({0, jin});

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second + cost;

			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				que.push({next_cost, next});
			}
		}
	}

	int min_A = INF, min_B = INF;
	for (int i=1; i<=n; ++i) {
		if (dict[i] == 'A')
			min_A = min(min_A, dist[i]);
		if (dict[i] == 'B')
			min_B = min(min_B, dist[i]);
	}

	if (min_A != INF || min_B != INF) {
		if (min_A > min_B)
			cout << "B\n";
		else
			cout << "A\n";
		cout << min(min_A, min_B) << '\n';
	} else {
		cout << "-1\n";
	}

	return 0;
}
