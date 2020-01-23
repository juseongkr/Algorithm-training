#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 1001

int n, k;
vector<int> x, y;
int dp[MAX][MAX];

int solve(int a, int b)
{
	if (a == n || b == n)
		return 0;

	if (~dp[a][b])
		return dp[a][b];

	int cost = 0;
	if (x[a] > y[b])
		cost = 2;
	else if (x[a] == y[b])
		cost = 1;

	dp[a][b] = max(solve(a, b+1), solve(a+1, b+1) + cost);
	return dp[a][b];
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> k;
		x.push_back(k);
	}

	for (int i=0; i<n; ++i) {
		cin >> k;
		y.push_back(k);
	}

	sort(x.rbegin(), x.rend());
	sort(y.rbegin(), y.rend());

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';

	return 0;
}
