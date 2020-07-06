#include <iostream>
#include <cstring>
using namespace std;
#define MAX 201

int T;
string s;
int dp[MAX][101][3];

int solve(int cur, int open, int prev)
{
	if (cur == s.length()-1)
		return open == 0 && prev != 2;

	if (open + cur > s.length()-1)
		return 0;

	int &ret = dp[cur][open][prev];
	if (~ret)
		return ret;

	ret = 0;
	if (prev == 0) {
		if (s[cur] == '{')
			ret |= solve(cur+1, open+1, 0);
		if (s[cur] == '}' && open > 0)
			ret |= solve(cur+1, open-1, 1);
		ret |= solve(cur+1, open, 1);
	} else if (prev == 1) {
		if (s[cur] == '}' && open > 0)
			ret |= solve(cur+1, open-1, 1);
		if (s[cur] == ',')
			ret |= solve(cur+1, open, 2);
	} else {
		if (s[cur] == '{')
			ret |= solve(cur+1, open+1, 0);
		ret |= solve(cur+1, open, 1);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	for (int i=1; i<=T; ++i) {
		cin >> s;
		if (s[0] == '{' && s[s.length()-1] == '}') {
			memset(dp, -1, sizeof(dp));
			if (solve(1, 0, 0))
				cout << "Word #" << i << ": Set\n";
			else
				cout << "Word #" << i << ": No Set\n";
		} else {
			cout << "Word #" << i << ": No Set\n";
		}
	}

	return 0;
}
