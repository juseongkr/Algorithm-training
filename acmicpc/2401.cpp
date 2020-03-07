#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001

int n;
string a, b;
int dp[MAX], fail[MAX], len[501];
bool match[MAX][501];

int solve(int cur)
{
	if (cur == a.length())
		return 0;

	if (~dp[cur])
		return dp[cur];

	dp[cur] = solve(cur+1);
	for (int i=0; i<n; ++i)
		if (match[cur][i])
			dp[cur] = max(dp[cur], solve(cur + len[i]) + len[i]);

	return dp[cur];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> a >> n;
	for (int k=0; k<n; ++k) {
		cin >> b;
		len[k] = b.length();
		if (b.length() > a.length())
			continue;
		fill(fail, fail+MAX, 0);
		for (int i=1, j=0; i<=b.length(); ++i) {
			while (j && b[i] != b[j])
				j = fail[j-1];

			if (b[i] == b[j])
				fail[i] = ++j;
		}

		for (int i=0, j=0; i<a.length(); ++i) {
			while (j && a[i] != b[j])
				j = fail[j-1];

			if (a[i] == b[j]) {
				if (j == b.length()-1) {
					match[i - b.length() + 1][k] = 1;
					j = fail[j];
				} else {
					j++;
				}
			}
		}
	}
	fill(dp, dp+MAX, -1);
	cout << solve(0) << '\n';

	return 0;
}
