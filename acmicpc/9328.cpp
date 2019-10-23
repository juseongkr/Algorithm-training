#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 101
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

string s;
int t, n, m;
bool key[MAX];
bool visit[MAX][MAX];
char map[MAX][MAX];

int main()
{
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=m; ++j)
				cin >> map[i][j];

		cin >> s;
		for (int i=0; i<s.length(); ++i) {
			if (s[i] == '0')
				continue;
			key[s[i]-'a'] = true;
		}

		queue<pair<int, int>> que, door[26];
		visit[0][0] = true;
		que.push({0, 0});

		int ans = 0;
		while (!que.empty()) {
			auto [x, y] = que.front();
			que.pop();

			for (int i=0; i<4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				char next = map[nx][ny];

				if (nx < 0 || nx > n+1 || ny < 0 || ny > m+1 || next == '*' || visit[nx][ny])
					continue;

				visit[nx][ny] = true;
				if ('A' <= next && next <= 'Z') {
					if (key[next-'A'])
						que.push({nx, ny});
					else
						door[next-'A'].push({nx, ny});
				} else if ('a' <= next && next <= 'z') {
					que.push({nx, ny});
					if (!key[next-'a']) {
						key[next-'a'] = true;
						while (!door[next-'a'].empty()) {
							que.push({door[next-'a'].front()});
							door[next-'a'].pop();
						}
					}
				} else {
					que.push({nx, ny});
					if (next == '$')
						ans++;
				}
			}
		}
		cout << ans << '\n';
		memset(map, 0, sizeof(map));
		memset(visit, false, sizeof(visit));
		fill(key, key+MAX, false);
	}

	return 0;
}
