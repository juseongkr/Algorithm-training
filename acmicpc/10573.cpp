#include <iostream>
#include <cstring>
using namespace std;
#define MAX 81

int t;
string s;
long long dp[MAX][10][2];

long long solve(int cur, int last, int flag)
{
	if (cur == s.length())
		return flag;

	if (~dp[cur][last][flag])
		return dp[cur][last][flag];

	dp[cur][last][flag] = 0;
	if (flag) {
		for (int i=last; i<=9; ++i)
			dp[cur][last][flag] += solve(cur+1, i, 1);
	} else {
		for (int i=last; i<s[cur]-'0'; ++i)
			dp[cur][last][flag] += solve(cur+1, i, 1);
		dp[cur][last][flag] += solve(cur+1, s[cur]-'0', 0);
	}

	return dp[cur][last][flag];
}

bool check(string s)
{
	for (int i=0; i<s.length()-1; ++i)
		if (s[i] > s[i+1])
			return false;
	return true;
}

int main()
{
	cin >> t;
	while (t--) {
		cin >> s;
		if (check(s)) {
			memset(dp, -1, sizeof(dp));
			cout << solve(0, 0, 0) << '\n';
		} else {
			cout << "-1\n";
		}
	}

	return 0;
}
