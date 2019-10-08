#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;
#define MAX 501

int dp[MAX][MAX];
int n, k, x, y;
vector<pair<int, int>> vec;

int dist(int x, int y)
{
	return abs(vec[x].first - vec[y].first) + abs(vec[x].second - vec[y].second);
}

int solve(int idx, int cnt)
{
	if (idx == n-1)
		return 0;

	if (dp[idx][cnt] != -1)
		return dp[idx][cnt];

	dp[idx][cnt] = INT_MAX;
	for (int i=0; i<=cnt; ++i)
		if (idx+i+1 < n)
			dp[idx][cnt] = min(dp[idx][cnt], solve(idx+i+1, cnt-i) + dist(idx, idx+i+1));

	return dp[idx][cnt];
}

int main()
{
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		vec.push_back({x, y});
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(0, k) << '\n';

	return 0;
}
