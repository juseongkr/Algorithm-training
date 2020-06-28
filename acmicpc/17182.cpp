#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 11
const int INF = 1e9+7;
typedef tuple<int, int, int> tp;

int n, k;
int map[MAX][MAX], dist[MAX][(1 << MAX)];
bool visit[MAX][(1 << MAX)];

int main()
{
	cin >> n >> k;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cin >> map[i][j];

	for (int i=0; i<n; ++i)
		fill(dist[i], dist[i]+(1 << MAX), INF);

	priority_queue<tp, vector<tp>, greater<tp>> que;
	que.push({0, k, (1 << k)});
	dist[k][(1 << k)] = 0;

	while (!que.empty()) {
		auto [cost, cur, bit] = que.top();
		que.pop();

		if (visit[cur][bit])
			continue;
		visit[cur][bit] = 1;

		if (bit == (1 << n)-1) {
			cout << cost << '\n';
			return 0;
		}

		for (int i=0; i<n; ++i) {
			int next_bit = bit | (1 << i);
			if (dist[i][next_bit] > cost + map[cur][i]) {
				dist[i][next_bit] = cost + map[cur][i];
				que.push({dist[i][next_bit], i, next_bit});
			}
		}
	}
	cout << "-1\n";

	return 0;
}
