#include <iostream>
using namespace std;
#define MAX 1001
#define INF_VAL 100001

int num[MAX], dp[MAX];
int n;

int solve(int s)
{
	if (s == n-1)
		return 0;
	if (s > n-1)
		return INF_VAL;
	if (dp[s] != -1)
		return dp[s];

	dp[s] = INF_VAL;
	for (int i=1; i<=num[s]; ++i)
		dp[s] = min(dp[s], solve(s+i) + 1);

	return dp[s];
}

int main()
{
	cin >> n;
	fill(dp, dp+MAX, -1);
	for (int i=0; i<n; ++i)
		cin >> num[i];

	int ans = solve(0);
	
	if (ans == INF_VAL)
		cout << "-1\n";
	else
		cout << ans << '\n';

	return 0;
}
