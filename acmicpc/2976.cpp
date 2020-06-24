#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001
const int INF = 1e9+7;

int n;
int cost[MAX], dp[MAX][MAX];

int solve(int cur, int jmp)
{
	if (cur == n-1)
		return cost[n-1];

	if (cur < 0 || cur >= n)
		return INF;

	if (~dp[cur][jmp])
		return dp[cur][jmp];

	return dp[cur][jmp] = min(solve(cur-jmp, jmp), solve(cur+jmp+1, jmp+1)) + cost[cur];
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> cost[i];

	memset(dp, -1, sizeof(dp));

	cout << solve(1, 1) << '\n';

	return 0;
}
