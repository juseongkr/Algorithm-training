#include <iostream>
#include <cstring>
using namespace std;
#define MAX_LEN 101
#define MAX_VOL 1001

int n, s, m;
int v[MAX_LEN], dp[MAX_LEN][MAX_VOL];

int solve(int cur, int vol)
{
	if (vol < 0 || vol > m)
		return -2;

	if (cur == n)
		return vol;

	if (dp[cur][vol] != -1)
		return dp[cur][vol];

	dp[cur][vol] = max(solve(cur+1, vol - v[cur+1]), solve(cur+1, vol + v[cur+1]));

	return dp[cur][vol];
}

int main()
{
	cin >> n >> s >> m;
	memset(dp, -1, sizeof(dp));
	for (int i=1; i<=n; ++i)
		cin >> v[i];
	
	int ans = solve(0, s);
	if (ans == -2)
		cout << "-1\n";
	else
		cout << ans << '\n';

	return 0;
}
