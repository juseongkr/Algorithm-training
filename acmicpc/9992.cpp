#include <iostream>
#include <cstring>
#include <map>
using namespace std;
#define MAX 101
#define MOD 2014

string s;
map<string, int> dp;

int solve(string p)
{
	if (dp.count(p))
		return dp[p];

	int ret = 1;
	int l = p.length();
	for (int i=1; i*2<l; ++i) {
		if (p.substr(0, i) == p.substr(l-i, i))
			ret += solve(p.substr(i, l-i));

		if (p.substr(0, i) == p.substr(i, i))
			ret += solve(p.substr(i, l-i));

		if (p.substr(0, i) == p.substr(l-i, i))
			ret += solve(p.substr(0, l-i));

		if (p.substr(l-i*2, i) == p.substr(l-i, i))
			ret += solve(p.substr(0, l-i));
	}

	dp[p] = ret % MOD;
	return dp[p];
}

int main()
{
	cin >> s;
	cout << solve(s)-1 << '\n';

	return 0;
}
