#include <iostream>
using namespace std;
#define MAX 41

string s;
int dp[MAX];

int solve(int cur)
{
	if (s[cur] == '0')
		return 0;

	if (cur > s.length())
		return 0;

	if (cur == s.length())
		return 1;

	if (~dp[cur])
		return dp[cur];

	dp[cur] = 0;
	if ((s[cur] == '1' || s[cur] == '2') || (s[cur] == '3' && s[cur+1] <= '4'))
		dp[cur] += solve(cur+2);
	dp[cur] += solve(cur+1);

	return dp[cur];
}

int main()
{
	cin >> s;
	fill(dp, dp+MAX, -1);
	cout << solve(0) << '\n';

	return 0;
}
