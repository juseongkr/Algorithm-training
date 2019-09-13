#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define MAX 251
const int INF = 1e9+7;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

vector<pair<int, int>> car, park;
vector<int> graph[MAX];
int A[MAX], B[MAX], visit[MAX];
int park_time[MAX][MAX], dist[MAX][MAX];
char map[51][51];
int n, m, cnt;

bool dfs(int a)
{
	visit[a] = 1;
	for (int i=0; i<graph[a].size(); ++i) {
		int b = graph[a][i];
		if (B[b] == -1 || (!visit[B[b]] && dfs(B[b]))) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int matching()
{
	int ret = 0;
	fill(A, A+MAX, -1);
	fill(B, B+MAX, -1);
	for (int i=0; i<MAX; ++i) {
		fill(visit, visit+MAX, 0);
		if (dfs(i))
			ret++;
	}
	return ret;
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'C')
				car.push_back({i, j});
			else if (map[i][j] == 'P')
				park.push_back({i, j});
		}
	}

	if (car.size() > park.size()) {
		cout << "-1\n";
		return 0;
	}

	if (car.size() == 0) {
		cout << "0\n";
		return 0;
	}

	for (int i=0; i<car.size(); ++i) {
		memset(dist, 0, sizeof(dist));
		queue<pair<int, int>> que;

		que.push(car[i]);
		dist[car[i].first][car[i].second] = 0;

		while (!que.empty()) {
			int x = que.front().first;
			int y = que.front().second;
			que.pop();

			for (int k=0; k<4; ++k) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m)
					continue;

				if (map[nx][ny] != 'X' && dist[nx][ny] == 0) {
					dist[nx][ny] = dist[x][y] + 1;
					que.push({nx, ny});
				}
			}
		}
		for (int j=0; j<park.size(); ++j)
			park_time[i][j] = dist[park[j].first][park[j].second];
	}

	int l = 1, r = n*m;
	int ans = INF;
	while (l <= r) {
		int mid = (l+r)/2;
		for (int i=0; i<car.size(); ++i) {
			for (int j=0; j<park.size(); ++j) {
				if (1 <= park_time[i][j] && park_time[i][j] <= mid)
					graph[i].push_back(j);
			}
		}

		if (matching() == car.size()) {
			ans = min(ans, mid);
			r = mid-1;
		} else {
			l = mid+1;
		}
		for (int i=0; i<MAX; ++i)
			graph[i].clear();
	}
	if (ans == INF)
		cout << "-1\n";
	else
		cout << ans << '\n';

	return 0;
}
