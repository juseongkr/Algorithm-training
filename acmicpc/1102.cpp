#include <iostream>
#include <cstring>
using namespace std;
#define MAX 17
const int INF = 1e9+7;

int n, p;
string s;
int a[MAX][MAX];
int dp[MAX][1<<MAX];

int solve(int cur, int bit)
{
	if (cur >= p)
		return 0;

	if (dp[cur][bit] != -1)
		return dp[cur][bit];

	dp[cur][bit] = INF;
	for (int i=0; i<n; ++i) {
		if (bit & (1 << i)) {
			for (int j=0; j<n; ++j) {
				if (i == j || bit & (1 << j))
					continue;
				dp[cur][bit] = min(dp[cur][bit], solve(cur+1, bit | (1 << j)) + a[i][j]);
			}
		}
	}
	return dp[cur][bit];
}


int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cin >> a[i][j];

	cin >> s >> p;
	int cnt = 0, bit = 0;
	for (int i=0; i<s.length(); ++i) {
		if (s[i] == 'Y') {
			bit |= (1 << i);
			cnt++;
		}
	}

	memset(dp, -1, sizeof(dp));
	int ans = solve(cnt, bit);
	if (ans != INF)
		cout << ans << '\n';
	else
		cout << "-1\n";

	return 0;
}
