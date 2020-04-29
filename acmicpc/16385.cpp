#include <iostream>
#include <cstring>
#include <map>
using namespace std;
#define MAX 21
const int INF = 1e9+7;

int n, idx;
int x[MAX], y[MAX], p[MAX];
int dp[MAX][(1 << 15)];
map<string, int> mp;
string s;

int solve(int cur, int bit)
{
	if (bit == (1 << idx)-1)
		return abs(x[cur]) + abs(y[cur]);

	if (~dp[cur][bit])
		return dp[cur][bit];

	dp[cur][bit] = INF;
	for (int i=0; i<n; ++i)
		if (i != cur)
			dp[cur][bit] = min(dp[cur][bit], solve(i, bit | (1 << p[i])) + abs(x[i]-x[cur]) + abs(y[i]-y[cur]));

	return dp[cur][bit];
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x[i] >> y[i] >> s;
		if (mp.count(s))
			p[i] = mp[s];
		else
			p[i] = mp[s] = idx++;
	}

	int ans = INF;
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<n; ++i)
		ans = min(ans, solve(i, (1 << p[i])) + abs(x[i]) + abs(y[i]));

	cout << ans << '\n';

	return 0;
}
