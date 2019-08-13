#include <iostream>
#include <cstring>
using namespace std;
#define MAX 10001

int n, m;
int tree[MAX];
int dp[MAX][31];

int solve(int cur, int mv)
{
	if (cur == n && mv <= m)
		return 0;

	if (mv > m)
		return 0;

	if (dp[cur][mv] != -1)
		return dp[cur][mv];

	int where = 0;
	if (tree[cur] == mv % 2 + 1)
		where = 1;
	dp[cur][mv] = max(solve(cur+1, mv), solve(cur+1, mv+1)) + where;

	return dp[cur][mv];
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> tree[i];

	memset(dp, -1, sizeof(dp));
	cout << max(solve(0, 0), solve(0, 1)) << '\n';

	return 0;
}
