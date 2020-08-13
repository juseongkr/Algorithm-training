#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 26
const int INF = 1e9+7;
typedef pair<int, int> pii;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n;
bool visit[MAX];
int map[MAX][MAX];
string s[MAX];
vector<int> graph[MAX*MAX];

bool check(int l, int r)
{
	for (int i=0; i<graph[l].size(); ++i)
		if (graph[l][i] == r)
			return false;
	return true;
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> s[i];

	int label = 1;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (map[i][j])
				continue;
			queue<pii> que;
			que.push({i, j});
			map[i][j] = label;

			while (!que.empty()) {
				auto [x, y] = que.front();
				que.pop();

				for (int d=0; d<4; ++d) {
					int nx = x + dx[d];
					int ny = y + dy[d];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny] || s[x][y] != s[nx][ny])
						continue;

					map[nx][ny] = label;
					que.push({nx, ny});
				}
			}
			label++;
		}
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			for (int d=0; d<4; ++d) {
				int nx = i + dx[d];
				int ny = j + dy[d];
				int l = map[i][j];
				int r = map[nx][ny];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n || l == r)
					continue;

				if (check(l, r))
					graph[l].push_back(r);
				if (check(r, l))
					graph[r].push_back(l);
			}
		}
	}

	int ans = INF;
	for (int k=1; k<label; ++k) {
		fill(visit, visit+label, 0);
		queue<pii> que;
		visit[k] = 1;
		que.push({k, 0});

		int dep = 0;
		while (!que.empty()) {
			auto [cur, cnt] = que.front();
			que.pop();

			dep = max(dep, cnt);
			for (int i=0; i<graph[cur].size(); ++i) {
				int next = graph[cur][i];

				if (!visit[next]) {
					visit[next] = 1;
					que.push({next, cnt+1});
				}
			}
		}
		ans = min(ans, dep);
	}

	cout << ans << '\n';

	return 0;
}
