#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dist[2][100001];

int main()
{
	int n, k;
	string s[2];
	bool flag = false;

	cin >> n >> k;
	for (int i=0; i<2; ++i)
		cin >> s[i];

	int dx[3] = {0, 0, 1};
	int dy[3] = {1, -1, k};

	memset(dist, -1, sizeof(dist));
	queue<pair<int, int>> que;
	que.push({0, 0});
	dist[0][0] = 0;

	while (!que.empty()) {
		auto [x, y] = que.front();
		que.pop();

		for (int i=0; i<3; ++i) {
			int nx = (x + dx[i]) % 2;
			int ny = (y + dy[i]);

			if (ny >= n) {
				flag = true;
				break;
			}

			if (ny < 0 || dist[nx][ny] != -1 || s[nx][ny] == '0' || ny < dist[x][y] + 1)
				continue;

			dist[nx][ny] = dist[x][y] + 1;
			que.push({nx, ny});
		}
		if (flag)
			break;
	}
	if (flag)
		cout << "1\n";
	else
		cout << "0\n";

	return 0;
}
