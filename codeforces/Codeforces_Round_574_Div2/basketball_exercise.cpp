#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100001
#define ll long long

int n;
ll a[MAX][2], dp[MAX][2];

ll _max(ll a, ll b) { return a < b ? b : a; }

ll solve(int cur, int row)
{
	if (cur == n)
		return 0;

	if (dp[cur][row] != -1)
		return dp[cur][row];

	dp[cur][row] = _max(solve(cur+1, 1-row) + a[cur][row], solve(cur+1, row));
	return dp[cur][row];
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i][0];
	for (int i=0; i<n; ++i)
		cin >> a[i][1];

	memset(dp, -1, sizeof(dp));
	cout << max(solve(0, 0), solve(0, 1)) << '\n';

	return 0;
}
