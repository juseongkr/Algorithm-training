#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX_LEN 2001
#define MAX_WEIGHT 10001

int dp[MAX_LEN][MAX_WEIGHT];
vector<int> w, v;
int n, k, a, b, c, t;

int solve(int cur, int weight)
{
	if (cur == w.size())
		return 0;

	if (dp[cur][weight] != -1)
		return dp[cur][weight];

	dp[cur][weight] = solve(cur+1, weight);
	if (weight >= w[cur])
		dp[cur][weight] = max(dp[cur][weight], solve(cur+1, weight-w[cur]) + v[cur]);

	return dp[cur][weight];
}

int main()
{
	cin >> n >> k;

	memset(dp, -1, sizeof(dp));
	for (int i=0; i<n; ++i) {
		cin >> a >> b >> c;
		for (int j=1; c>0; j*=2) {
			int t = min(j, c);
			w.push_back(a * t);
			v.push_back(b * t);
			c -= t;
		}
	}
	cout << solve(0, k) << '\n';

	return 0;
}
