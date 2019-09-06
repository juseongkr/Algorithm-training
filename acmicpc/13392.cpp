#include <iostream>
#include <cstring>
using namespace std;
#define MAX 10001

int n;
int a[MAX], b[MAX];
int dp[MAX][10];
string s1, s2;

int solve(int idx, int turn)
{
	if (idx == n)
		return 0;

	if (dp[idx][turn] != -1)
		return dp[idx][turn];

	int cur = (a[idx] + turn) % 10;
	int l = (b[idx] - cur + 10) % 10;
	int r = (cur - b[idx] + 10) % 10;

	int left = solve(idx+1, (turn + l) % 10) + l;
	int right = solve(idx+1, turn) + r;

	dp[idx][turn] = min(left, right);
	return dp[idx][turn];
}

int main()
{
	cin >> n >> s1 >> s2;
	for (int i=0; i<n; ++i) {
		a[i] = s1[i]-'0';
		b[i] = s2[i]-'0';
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';

	return 0;
}
