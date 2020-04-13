#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001
const int INF = 1e9+7;

int n, m;
string s, p, u, v;
int dp[MAX][MAX];

int solve(int a, int b)
{
	if (a == n || b == m)
		return 0;

	if (dp[a][b] != -INF)
		return dp[a][b];

	dp[a][b] = 0;
	dp[a][b] = max(dp[a][b], solve(a+1, b+1) + (s[a] == p[b] ? 3 : -2));
	dp[a][b] = max(dp[a][b], solve(a+1, b) - 2);
	dp[a][b] = max(dp[a][b], solve(a, b+1) - 2);

	return dp[a][b];
}

void tracing(int a, int b)
{
	if (solve(a, b) == 0)
		return;

	int X = solve(a, b);
	int AB = solve(a+1, b+1) + (s[a] == p[b] ? 3 : -2);
	int A = solve(a+1, b) - 2;
	int B = solve(a, b+1) - 2;

	if (X == AB) {
		u += s[a];
		v += p[b];
		tracing(a+1, b+1);
	} else if (X == A) {
		u += s[a];
		tracing(a+1, b);
	} else if (X == B) {
		v += p[b];
		tracing(a, b+1);
	}
}

int main()
{
	cin >> n >> s >> m >> p;
	for (int i=0; i<=n; ++i)
		for (int j=0; j<=m; ++j)
			dp[i][j] = -INF;

	int ans = -INF, x = 0, y = 0;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (s[i] == p[j]) {
				int ret = solve(i, j);
				if (ans < ret) {
					ans = ret;
					x = i;
					y = j;
				}
			}
		}
	}
	tracing(x, y);
	cout << ans << '\n' << u << '\n' << v << '\n';

	return 0;
}
