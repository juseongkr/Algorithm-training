#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
#define MAX 301

int n, m, k, a, b, c;
int map[MAX][MAX], dp[MAX][MAX];

int solve(int cur, int cnt)
{
	if (cur == n)
		return 0;
	if (cnt == m)
		return INT_MIN;

	if (dp[cur][cnt] != -1)
		return dp[cur][cnt];

	dp[cur][cnt] = 0;
	for (int i=cur+1; i<=n; ++i) {
		if (map[cur][i])
			dp[cur][cnt] = max(dp[cur][cnt], solve(i, cnt+1) + map[cur][i]);
	}
	return dp[cur][cnt];
}

int main()
{
	cin >> n >> m >> k;
	for (int i=0; i<k; ++i) {
		cin >> a >> b >> c;
		map[a][b] = max(map[a][b], c);
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(1, 1) << '\n';

	return 0;
}
