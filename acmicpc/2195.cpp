#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001
const int INF = 1e9+7;

string s, p;
int dp[MAX];

int solve(int cur)
{
	if (cur == p.length())
		return 0;

	if (~dp[cur])
		return dp[cur];

	dp[cur] = INF;
	for (int i=0; i<s.length(); ++i) {
		if (s[i] == p[cur]) {
			int k = 0;
			while (i+k < s.length() && cur+k < p.length() && s[i+k] == p[cur+k]) {
				k++;
			}
			dp[cur] = min(dp[cur], solve(cur+k)+1);
		}
	}

	return dp[cur];
}

int main()
{
	cin >> s >> p;
	memset(dp, -1, sizeof(dp));
	cout << solve(0) << '\n';

	return 0;
}
