#include <iostream>
#include <cstring>
using namespace std;
#define MAX 16

int n;
string s;
int cost[MAX][MAX];
int dp[MAX][10][(1 << MAX)];

int solve(int cur, int last, int bit)
{
	if (bit == (1 << n)-1)
		return 1;

	int &ret = dp[cur][last][bit];
	if (~ret)
		return ret;

	ret = 1;
	for (int i=0; i<n; ++i)
		if (cur != i && last <= cost[cur][i] && !(bit & (1 << i)))
			ret = max(ret, solve(i, cost[cur][i], bit | (1 << i)) + 1);

	return ret;
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> s;
		for (int j=0; j<n; ++j)
			cost[i][j] = s[j]-'0';
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0, (1 << 0)) << '\n';

	return 0;
}
