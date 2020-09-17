#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 21
const int INF = 1e9+7;

char c;
int n, m, a, b;
vector<pair<int, char>> graph[MAX];
bool visit[MAX][MAX];
int dp[MAX][MAX];

int solve(int x, int y)
{
	if (x == y)
		return 0;

	if (~dp[x][y])
		return dp[x][y];

	for (int i=0; i<graph[x].size(); ++i) {
		int next = graph[x][i].first;
		if (next == y)
			return 1;
	}

	visit[x][y] = true;
	for (int i=0; i<graph[x].size(); ++i) {
		auto l = graph[x][i];
		for (int j=0; j<graph[y].size(); ++j) {
			auto r = graph[y][j];

			if (l.second != r.second || visit[l.first][r.first])
				continue;

			int ret = solve(l.first, r.first);
			if (ret == -1)
				continue;

			if (dp[x][y] == -1 || dp[x][y] > ret + 2)
				dp[x][y] = ret + 2;
		}
	}
	visit[x][y] = false;

	return dp[x][y];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 1) << '\n';

	return 0;
}
