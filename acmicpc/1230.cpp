#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001
const int INF = 1e9+7;

string s, p;
int dp[MAX][MAX][2];

int solve(int a, int b, bool v)
{
	if (a == s.length())
		return b < p.length();

	if (b == p.length())
		return INF;

	if (~dp[a][b][v])
		return dp[a][b][v];

	dp[a][b][v] = min(INF, solve(a, b+1, 0) + v);
	if (s[a] == p[b])
		dp[a][b][v] = min(dp[a][b][v], solve(a+1, b+1, 1));

	return dp[a][b][v];
}

int main()
{
	getline(cin, s);
	getline(cin, p);

	memset(dp, -1, sizeof(dp));
	int ans = solve(0, 0, 1);
	if (ans == INF)
		cout << "-1\n";
	else
		cout << ans << '\n';

	return 0;
}
