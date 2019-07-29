#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001

int n;
string s;
int num[MAX], dp[MAX];

int solve(int cur)
{
	if (cur == n-1)
		return 0;

	if (dp[cur] != -1)
		return dp[cur];

	dp[cur] = 1e9+7;
	for (int i=cur; i<n; ++i)
		if ((num[cur]+1) % 3 == num[i])
			dp[cur] = min(dp[cur], solve(i) + (i - cur) * (i - cur));
	return dp[cur];
}

int main()
{
	cin >> n >> s;
	for (int i=0; i<s.length(); ++i) {
		if (s[i] == 'B')
			num[i] = 0;
		else if (s[i] == 'O')
			num[i] = 1;
		else
			num[i] = 2;
	}

	memset(dp, -1, sizeof(dp));
	int ans = solve(0);
	if (ans == (int)1e9+7)
		cout << "-1\n";
	else
		cout << ans << '\n';

	return 0;
}
