#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 10001
const int INF = 1e9+7;

int n, x, y;
int dp[MAX];
vector<pair<int, int>> point;

int solve(int k)
{
	if (k <= 0)
		return 0;

	if (dp[k] != -1)
		return dp[k];

	int max_val = 0;
	int min_val = INF;
	for (int i=k; i>=1; i--) {
		max_val = max(max_val, abs(point[i].second));
		min_val = min(min_val, solve(i-1) + max(point[k].first - point[i].first, max_val * 2));
	}
	dp[k] = min_val;

	return dp[k];
}

int main()
{
	cin >> n;
	point.resize(n+1);
	for (int i=1; i<=n; ++i) {
		cin >> x >> y;
		point[i] = {x, y};
	}

	sort(point.begin()+1, point.end());

	memset(dp, -1, sizeof(dp));
	cout << solve(n) << '\n';

	return 0;
}
