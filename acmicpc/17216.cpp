#include <iostream>
using namespace std;
#define MAX 1001

int n, ans;
int num[MAX], dp[MAX];

int solve(int cur)
{
	if (cur == n)
		return 0;

	if (dp[cur] != -1)
		return dp[cur];

	dp[cur] = 0;
	for (int i=cur+1; i<n; ++i)
		if (num[cur] > num[i])
			dp[cur] = max(dp[cur], solve(i) + num[i]);

	return dp[cur];
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	fill(dp, dp+MAX, -1);
	for (int i=0; i<n; ++i)
		ans = max(ans, solve(i) + num[i]);

	cout << ans << '\n';

	return 0;
}
