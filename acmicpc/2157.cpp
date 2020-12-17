#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int INF = 1e9+7;
#define MAX 301

int n, m, k, a, b, c;
int map[MAX][MAX], dp[MAX][MAX];
vector<int> graph[MAX];

int solve(int cur, int cnt)
{
	if (cur == n)
		return 0;
	if (cnt == 1)
		return map[cur][n] ? map[cur][n] : -INF;

	if (~dp[cur][cnt])
		return dp[cur][cnt];

	dp[cur][cnt] = -INF;
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		int value = solve(next, cnt-1);

		if (value != -INF)
			dp[cur][cnt] = max(dp[cur][cnt], value + map[cur][next]);
	}

	return dp[cur][cnt];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=0; i<k; ++i) {
		cin >> a >> b >> c;
		if (a < b) {
			map[a][b] = max(map[a][b], c);
			graph[a].push_back(b);
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(1, m-1) << '\n';

	return 0;
}
