#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
#define MAX 2501

string s;
int dp[MAX][MAX];
int d[MAX];

int check(int l, int r)
{
	if (l >= r)
		return 1;
	if (s[l] != s[r])
		return 0;

	if (dp[l][r] != -1)
		return dp[l][r];

	dp[l][r] = check(l+1, r-1);
	return dp[l][r];
}

int main()
{
	cin >> s;
	s = " " + s;
	memset(dp, -1, sizeof(dp));
	fill(d, d+MAX, INT_MAX);

	d[0] = 0;
	for (int i=1; i<=s.length()-1; ++i) {
		d[i] = d[i-1] + 1;
		for (int j=1; j<i; ++j) {
			if (check(j, i))
				d[i] = min(d[i], d[j-1] + 1);
		}
	}
	cout << d[s.length()-1] << '\n';

	return 0;
}
