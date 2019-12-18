#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1002
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

string s;
int n, label;
char map[MAX][MAX];
int visit[MAX][MAX], area[MAX*MAX], peri[MAX*MAX];

void dfs(int x, int y)
{
	area[label]++;
	visit[x][y] = label;
	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 1 || nx > n || ny < 1 || ny > n || map[nx][ny] == '.' || visit[nx][ny])
			continue;

		dfs(nx, ny);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> s;
		for (int j=1; j<=n; ++j)
			map[i][j] = s[j-1];
	}

	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			if (map[i][j] == '#' && !visit[i][j]) {
				label++;
				dfs(i, j);
			}
		}
	}

	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			if (!visit[i][j])
				continue;

			for (int k=0; k<4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (!visit[nx][ny])
					peri[visit[i][j]]++;
			}

		}
	}

	vector<pair<int, int>> vec;
	for (int i=1; i<=label; ++i)
		vec.push_back({area[i], -peri[i]});

	sort(vec.begin(), vec.end());

	cout << vec[vec.size()-1].first << ' ' << -vec[vec.size()-1].second << '\n';

	return 0;
}
