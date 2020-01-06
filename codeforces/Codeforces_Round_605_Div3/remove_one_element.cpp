#include <iostream>
#include <cstring>
using namespace std;
#define MAX 200001

int n;
long long num[MAX], dp[MAX][2][2];

long long solve(int cur, int k, int l)
{
	if (cur == n)
		return 0;

	if (dp[cur][k][l] != -1)
		return dp[cur][k][l];

	dp[cur][k][l] = 0;
	int prev = cur-1;
	if (k && l)
		prev--;

	if (num[cur] > num[prev])
		dp[cur][k][l] = max(dp[cur][k][l], solve(cur+1, k, 0) + 1);
	if (k == 0)
		dp[cur][k][l] = max(dp[cur][k][l], solve(cur+1, 1, 1));

	return dp[cur][k][l];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	memset(dp, -1, sizeof(dp));
	long long ans = 0;
	for (int i=1; i<=n; ++i)
		ans = max(ans, solve(i, 0, 0) + 1);

	cout << ans << '\n';

	return 0;
}
