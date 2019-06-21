#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 1001

int n;
int dp[MAX][MAX];
pair<int, int> arr[MAX];

int solve(int cur, int val)
{
	if (cur == n)
		return 0;

	if (dp[cur][val] != -1)
		return dp[cur][val];

	dp[cur][val] = max(dp[cur][val], solve(cur+1, val));
	if (val <= arr[cur].first)
		dp[cur][val] = max(dp[cur][val], solve(cur+1, val+1) + arr[cur].second);
	return dp[cur][val];
}

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<n; ++i)
		cin >> arr[i].first >> arr[i].second;

	sort(arr, arr+n);

	cout << solve(0, 1) << '\n';

	return 0;
}
