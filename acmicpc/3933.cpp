#include <iostream>
#include <cstring>
using namespace std;

int n;
int dp[(1<<15)+1][183][4];

int solve(int sum, int num, int cnt)
{
	if (sum == 0)
		return 1;

	if (num >= 183 || cnt >= 4)
		return 0;

	if (dp[sum][num][cnt] != -1)
		return dp[sum][num][cnt];

	dp[sum][num][cnt] = solve(sum, num+1, cnt);
	if (num * num <= sum)
		dp[sum][num][cnt] += solve(sum-num*num, num, cnt+1);

	return dp[sum][num][cnt];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));
	while (1) {
		cin >> n;
		if (n == 0)
			break;
		cout << solve(n, 1, 0) << '\n';
	}

	return 0;
}
