#include <iostream>
#include <cstring>
using namespace std;

string s;
int n, cnt;
int dp[16][110][2];
long long S, E, over = 1;
const int digit[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 5};

bool solve(int cur, int left, bool ok)
{
	if (cur == n)
		return !left && !ok;

	if (~dp[cur][left][ok])
		return dp[cur][left][ok];

	dp[cur][left][ok] = 0;
	int idx = ok ? s[cur]-'0' : 0;
	for (int i=idx; i<=9; ++i)
		if (digit[i] <= left)
			if (solve(cur+1, left - digit[i], (ok && i == s[cur]-'0')))
				dp[cur][left][ok] = 1;

	return dp[cur][left][ok];
}

void print(int cur, int left, bool ok)
{
	if (cur == n)
		return;

	int idx = ok ? s[cur]-'0' : 0;
	for (int i=idx; i<=9; ++i) {
		if (digit[i] <= left) {
			if (solve(cur+1, left - digit[i], (ok && i == s[cur]-'0'))) {
				E = E * 10 + i;
				print(cur+1, left - digit[i], (ok && i == s[cur]-'0'));
				return;
			}
		}
	}
}

int main()
{
	cin >> s;
	n = s.length();
	for (int i=0; i<n; ++i) {
		cnt += digit[s[i]-'0'];
		S = S * 10 + (s[i]-'0');
		over *= 10;
	}

	memset(dp, -1, sizeof(dp));
	if (solve(0, cnt, 1)) {
		print(0, cnt, 1);
		cout << E - S << '\n';
	} else {
		print(0, cnt, 0);
		cout << E - S + over << '\n';
	}

	return 0;
}
