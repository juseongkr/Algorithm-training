#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1000001

int k;
int dp[11][MAX];
string n;

int solve(int cnt, string s)
{
	int num = stoi(s);
	if (cnt == k)
		return num;

	if (~dp[cnt][num])
		return dp[cnt][num];

	for (int i=0; i<s.length(); ++i) {
		for (int j=i+1; j<s.length(); ++j) {
			if (s[j] == '0' && i == 0)
				continue;
			swap(s[i], s[j]);
			dp[cnt][num] = max(dp[cnt][num], solve(cnt+1, s));
			swap(s[i], s[j]);
		}
	}
	return dp[cnt][num];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	cout << solve(0, n) << '\n';

	return 0;
}
