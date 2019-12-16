#include <iostream>
using namespace std;
#define MAX 10001

int n, k;
int skill[MAX], dp[MAX];

int solve(int cur)
{
	if (cur == n)
		return 0;

	if (dp[cur] != -1)
		return dp[cur];
	
	dp[cur] = 0;
	int val = skill[cur];
	for (int i=1; i<=k; ++i) {
		if (cur+i > n)
			continue;
		val = max(val, skill[cur+i-1]);
		dp[cur] = max(dp[cur], solve(cur+i) + val * i);
	}

	return dp[cur];
}

int main()
{
	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> skill[i];

	fill(dp, dp+MAX, -1);
	cout << solve(0) << '\n';

	return 0;
}
