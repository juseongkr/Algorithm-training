#include <iostream>
#include <cstring>
using namespace std;
#define MAX_LEN 21
#define MAX_VAL 101

int dp[MAX_LEN][MAX_VAL];
int l[MAX_LEN], h[MAX_LEN];
int n;

int solve(int cur, int hp)
{
	if (cur == n)
		return 0;

	if (dp[cur][hp] != -1)
		return dp[cur][hp];

	dp[cur][hp] = solve(cur + 1, hp);
	if (hp > l[cur])
		dp[cur][hp] = max(dp[cur][hp], solve(cur + 1, hp - l[cur]) + h[cur]);

	return dp[cur][hp];
}

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<n; ++i)
		cin >> l[i];
	for (int i=0; i<n; ++i)
		cin >> h[i];

	cout << solve(0, 100) << '\n';

	return 0;
}
