#include <iostream>
using namespace std;
#define MAX 1001

int n, num[MAX], dp[MAX];

int dfs(int s)
{
	if (s == n)
		return 0;

	if (dp[s] != -1)
		return dp[s];

	dp[s] = 0;
	int min_val = 1e9;
	int max_val = 0;
	for (int i=s; i<n; ++i) {
		min_val = min(min_val, num[i]);
		max_val = max(max_val, num[i]);
		int k = max_val - min_val;
		dp[s] = max(dp[s], dfs(i+1) + k);
	}
	return dp[s];
}

int main()
{
	cin >> n;
	fill(dp, dp+MAX, -1);
	for (int i=0; i<n; ++i)
		cin >> num[i];

	cout << dfs(0) << '\n';

	return 0;
}
