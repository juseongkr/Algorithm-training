#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101

int n;
int num[MAX];
long long dp[MAX][MAX];

long long solve(int cur, int val)
{
	if (cur == n-2) {
		if (val == num[n-1])
			return 1;
		else
			return 0;
	}
	if (dp[cur][val] != -1)
		return dp[cur][val];

	dp[cur][val] = 0;
	if (val + num[cur+1] <= 20)
		dp[cur][val] += solve(cur+1, val + num[cur+1]);
	if (val - num[cur+1] >= 0)
		dp[cur][val] += solve(cur+1, val - num[cur+1]);

	return dp[cur][val];
}

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<n; ++i)
		cin >> num[i];

	cout << solve(0, num[0]) << '\n';

	return 0;
}
