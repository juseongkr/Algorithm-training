#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101
const int INF = 1e9+7;

int n, m, k;
int x[MAX], y[MAX], dp[MAX][MAX];

int solve(int cur, int hp)
{
	if (cur == n)
		return hp == 0 ? 0 : INF;

	if (~dp[cur][hp])
		return dp[cur][hp];

	dp[cur][hp] = solve(cur+1, hp);
	for (int i=1; ; ++i) {
		int sp = y[cur] * i;
		if (sp > hp)
			break;
		dp[cur][hp] = min(dp[cur][hp], solve(cur+1, hp-sp) + x[cur]*i + i*(i-1)/2*k);
	}

	return dp[cur][hp];
}

int main()
{
	cin >> n >> m >> k;
	for (int i=0; i<n; ++i)
		cin >> x[i] >> y[i];

	memset(dp, -1, sizeof(dp));

	cout << solve(0, m) << '\n';

	return 0;
}
