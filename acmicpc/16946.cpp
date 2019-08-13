#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define MAX 1001

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
int n, m, num;
int map[MAX][MAX], visit[MAX][MAX], group[MAX][MAX];
vector<int> area;

void bfs(int y, int x)
{
	queue<pair<int, int>> que;
	que.push({y, x});
	visit[y][x] = 1;
	group[y][x] = num;

	int cnt = 1;
	while (!que.empty()) {
		int cy = que.front().first;
		int cx = que.front().second;
		que.pop();

		for (int i=0; i<4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			if (!visit[ny][nx] && map[ny][nx] == 0) {
				visit[ny][nx] = 1;
				group[ny][nx] = num;
				que.push({ny, nx});
				cnt++;
			}
		}
	}
	num++;
	area.push_back(cnt);
}

int main()
{
	string s;

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> s;
		for (int j=0; j<m; ++j)
			map[i][j] = s[j]-'0';
	}

	memset(group, -1, sizeof(group));
	memset(visit, 0, sizeof(visit));
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (!visit[i][j] && map[i][j] == 0)
				bfs(i, j);

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (map[i][j] == 1) {
				set<int> st;
				int ans = 1;
				for (int k=0; k<4; ++k) {
					int ny = i + dy[k];
					int nx = j + dx[k];

					if (ny < 0 || nx < 0 || ny >= n || nx >= m)
						continue;

					if (map[ny][nx] == 0)
						st.insert(group[ny][nx]);
				}

				for (auto it=st.begin(); it!=st.end(); it++)
					ans += area[*it];

				cout << ans % 10;
			} else {
				cout << "0";
			}
		}
		cout << '\n';
	}

	return 0;
}
