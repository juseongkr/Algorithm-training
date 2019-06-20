#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101

int dp[MAX][10001], c[MAX], m[MAX];
int N, M;

int solve(int cur, int val)
{
	if (cur == N)
		return 0;

	if (dp[cur][val] != -1)
		return dp[cur][val];

	dp[cur][val] = solve(cur+1, val);
	if (val >= c[cur])
		dp[cur][val] = max(dp[cur][val], solve(cur+1, val-c[cur]) + m[cur]);
	return dp[cur][val];
}

int main()
{

	cin >> N >> M;
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<N; ++i)
		cin >> m[i];

	for (int i=0; i<N; ++i)
		cin >> c[i];

	int cost = 1;
	while (solve(0, cost) < M)
		cost++;

	cout << cost << '\n';

	return 0;
}
