#include <iostream>
#include <functional>
#include <tuple>
#include <vector>
#include <queue>
using namespace std;
#define MAX 21
typedef tuple<int, int, int> tiii;
const int INF = 1e9+7;

int a[MAX][MAX], b[MAX][MAX];
int dist[MAX][MAX*9], visit[MAX][MAX*9];

int main()
{
	int n;
	char c;

	cin >> n;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> c;
			if (c != '.')
				a[i][j] = c-'0';
		}
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> c;
			if (c != '.')
				b[i][j] = c-'0';
		}
	}

	for (int i=0; i<n; ++i)
		for (int j=0; j<n*9; ++j)
			dist[i][j] = INF;

	priority_queue<tiii, vector<tiii>, greater<tiii>> que;
	que.push({0, 0, 0});
	dist[0][0] = 0;

	while (!que.empty()) {
		auto [_, cur, step] = que.top();
		que.pop();

		if (visit[cur][step])
			continue;

		visit[cur][step] = 1;
		for (int i=0; i<n; ++i) {
			if (!a[cur][i])
				continue;

			int d1 = dist[cur][step] + a[cur][i];
			int d2 = step + b[cur][i];

			if (d2 >= n*9)
				continue;

			if (dist[i][d2] > d1) {
				dist[i][d2] = d1;
				que.push({dist[i][d2], i, d2});
			}
		}
	}

	int ans = INF;
	for (int i=0; i<n*9; ++i) {
		if (visit[1][i])
			ans = min(ans, dist[1][i] * i);
	}

	if (ans == INF)
		cout << "-1\n";
	else
		cout << ans << '\n';

	return 0;
}
