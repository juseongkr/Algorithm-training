#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101

int n, m;
int p[MAX];
int dp[MAX][11][2001];

int solve(int cur, int cnt, int dir)
{
	if (cur == n)
		return 0;

	if (~dp[cur][cnt][dir])
		return dp[cur][cnt][dir];

	dp[cur][cnt][dir] = solve(cur+1, cnt, dir + p[cur]) + dir * p[cur];
	if (cnt)
		dp[cur][cnt][dir] = min(dp[cur][cnt][dir], solve(cur+1, cnt-1, 0) + dir * p[cur]);

	return dp[cur][cnt][dir];
}

void print(int cur, int cnt, int dir)
{
	if (cur == n)
		return;

	if (cnt && solve(cur+1, cnt-1, 0) <= solve(cur+1, cnt, dir + p[cur])) {
		cout << cur+1 << " ";
		print(cur+1, cnt-1, 0);
	} else {
		print(cur+1, cnt, dir + p[cur]);
	}
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> p[i];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, m, 0) << '\n';
	print(0, m, 0);

	return 0;
}
