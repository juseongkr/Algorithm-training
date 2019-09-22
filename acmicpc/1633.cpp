#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> white, black;
int dp[1001][16][16];

int solve(int cur, int w, int b)
{
	if (cur == white.size())
		return 0;

	if (dp[cur][w][b] != -1)
		return dp[cur][w][b];

	if (w > 0)
		dp[cur][w][b] = max(dp[cur][w][b], solve(cur+1, w-1, b) + white[cur]);
	if (b > 0)
		dp[cur][w][b] = max(dp[cur][w][b], solve(cur+1, w, b-1) + black[cur]);
	dp[cur][w][b] = max(dp[cur][w][b], solve(cur+1, w, b));

	return dp[cur][w][b];
}

int main()
{
	int w, b;

	memset(dp, -1, sizeof(dp));
	while (cin >> w >> b) {
		white.push_back(w);
		black.push_back(b);
	}
	cout << solve(0, 15, 15) << '\n';

	return 0;
}
