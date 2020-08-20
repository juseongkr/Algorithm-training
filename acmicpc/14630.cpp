#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001
const int INF = 1e9+7;
typedef pair<int, int> pii;

int n, src, sink;
int cost[MAX][MAX], dist[MAX];
bool visit[MAX];
string s[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> s[i];
		for (int j=0; j<i; ++j) {
			for (int k=0; k<s[i].length(); ++k)
				cost[i][j] += (s[i][k]-s[j][k]) * (s[i][k]-s[j][k]);
			cost[j][i] = cost[i][j];
		}
	}
	cin >> src >> sink;
	src--;
	sink--;

	fill(dist, dist+n, INF);
	priority_queue<pii, vector<pii>, greater<pii>> que;
	que.push({0, src});
	dist[src] = 0;

	while (!que.empty()) {
		auto [cst, cur] = que.top();
		que.pop();

		if (cur == sink) {
			cout << cst << '\n';
			return 0;
		}

		if (visit[cur])
			continue;
		visit[cur] = 1;

		for (int next=0; next<n; ++next) {
			int next_cst = cost[cur][next] + cst;
			if (dist[next] > next_cst) {
				dist[next] = next_cst;
				que.push({dist[next], next});
			}
		}
	}

	return 0;
}
