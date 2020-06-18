#include <iostream>
#include <functional>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define MAX 51
typedef pair<int, int> pii;
const int INF = 1e8+7;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n;
string map[MAX];
int dist[MAX][MAX];

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> map[i];

	for (int i=0; i<n; ++i)
		fill(dist[i], dist[i]+n, INF);

	queue<pii> que;
	que.push({0, 0});
	dist[0][0] = 0;

	while (!que.empty()) {
		auto [x, y] = que.front();
		que.pop();

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;

			int cost = (map[nx][ny] == '1' ? 0 : 1);
			if (dist[nx][ny] > dist[x][y] + cost) {
				dist[nx][ny] = dist[x][y] + cost;
				que.push({nx, ny});
			}
		}
	}
	cout << dist[n-1][n-1] << '\n';

	return 0;
}
