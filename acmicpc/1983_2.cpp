#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 401
const int INF = 1e9+7;

int n, t;
int dp[MAX][MAX][MAX];
vector<int> a, b;

int solve(int i, int x, int y)
{
	if (x == a.size() && y == b.size())
		return 0;

	if (i <= 0)
		return -INF;

	if (dp[i][x][y] != -INF)
		return dp[i][x][y];

	if (x < a.size())
		dp[i][x][y] = max(dp[i][x][y], solve(i-1, x+1, y));

	if (y < b.size())
		dp[i][x][y] = max(dp[i][x][y], solve(i-1, x, y+1));

	if (x < a.size() && y < b.size())
		dp[i][x][y] = max(dp[i][x][y], solve(i-1, x+1, y+1) + a[x] * b[y]);
	
	return dp[i][x][y];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> t;
		if (t != 0)
			a.push_back(t);
	}

	for (int i=0; i<n; ++i) {
		cin >> t;
		if (t != 0)
			b.push_back(t);
	}

	for (int i=0; i<MAX; ++i)
		for (int j=0; j<MAX; ++j)
			for (int k=0; k<MAX; ++k)
				dp[i][j][k] = -INF;

	cout << solve(n, 0, 0) << '\n';

	return 0;
}
