#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101

int n, x, cnt;
int l[MAX], c[MAX];
int dp[MAX][10001];

int solve(int cur, int len)
{	
	if (len == 0)
		return 1;

	if (cur == n)
		return 0;

	if (dp[cur][len] != -1)
		return dp[cur][len];

	dp[cur][len] = 0;
	for (int i=0; i<cnt; ++i) {
		if (i <= c[cur] && l[cur] * i <= len)
			dp[cur][len] += solve(cur+1, len - l[cur] * i);
		else
			break;
	}

	return dp[cur][len];
}

int main()
{
	cin >> n >> x;
	for (int i=0; i<n; ++i) {
		cin >> l[i] >> c[i];
		cnt += l[i] * c[i];
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(0, x) << '\n';

	return 0;
}
