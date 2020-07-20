#include <iostream>
#include <cstring>
using namespace std;
#define MAX 18
const int INF = 1e9+7;

int n;
string s;
int dp[MAX][(1 << MAX)];

int solve(int cur, int bit)
{
	if (bit == (1 << n)-1)
		return 0;

	if (~dp[cur][bit])
		return dp[cur][bit];

	dp[cur][bit] = INF;
	for (int i=0; i<n; ++i) {
		if (!(bit & (1 << i))) {
			int push = 0;
			int ch = abs(s[i]-s[cur]);
			ch = min(ch, 26-ch);
			if (i < cur) {
				push++;
				for (int j=i+1; j<cur; ++j)
					if (bit & (1 << j))
						push++;
			} else {
				for (int j=cur+1; j<i; ++j)
					if (bit & (1 << j))
						push++;
			}
			dp[cur][bit] = min(dp[cur][bit], solve(i, bit | (1 << i)) + ch + push + 1);
		}
	}

	return dp[cur][bit];
}

int main()
{
	while (1) {
		cin >> s;
		if (s == "0")
			break;

		n = s.length();
		int ans = INF;
		memset(dp, -1, sizeof(dp));
		for (int i=0; i<n; ++i) {
			int ch = s[i]-'A';
			ch = min(ch, 26-ch);
			ans = min(ans, solve(i, (1 << i)) + ch + 1);
		}
		cout << ans << '\n';
	}

	return 0;
}
