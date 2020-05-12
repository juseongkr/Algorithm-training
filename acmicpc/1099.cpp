#include <iostream>
#include <cstring>
using namespace std;
#define MAX 51
const int INF = 1e9+7;

int n;
int dp[MAX], dict[26];
string s, p[MAX];

int solve(int idx)
{
	if (idx == s.length())
		return 0;

	if (~dp[idx])
		return dp[idx];

	dp[idx] = INF;
	for (int i=0; i<n; ++i) {
		if (s.length() < p[i].length() + idx)
			continue;

		fill(dict, dict+26, 0);
		for (int j=0; j<p[i].length(); ++j) {
			dict[s[idx+j]-'a']++;
			dict[p[i][j]-'a']--;
		}

		bool flag = false;
		for (int j=0; j<26; ++j) {
			if (dict[j]) {
				flag = true;
				break;
			}
		}
		if (flag)
			continue;

		int cnt = 0;
		for (int j=0; j<p[i].length(); ++j)
			if (s[idx+j] != p[i][j])
				cnt++;

		dp[idx] = min(dp[idx], solve(idx + p[i].length()) + cnt);
	}

	return dp[idx];
}

int main()
{
	cin >> s >> n;
	for (int i=0; i<n; ++i)
		cin >> p[i];

	memset(dp, -1, sizeof(dp));
	int ans = solve(0);
	if (ans == INF)
		cout << "-1\n";
	else
		cout << ans << '\n';

	return 0;
}
