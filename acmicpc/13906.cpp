#include <iostream>
using namespace std;
#define MAX 2001
const int MOD = 1e9+7;

int m[26], dp[MAX];

int main()
{
	string s;

	cin >> s;
	int len = s.length();
	for (int i=len; i>=0; i--) {
		dp[i] = 1;
		fill(m, m+26, 0);
		for (int j=i; j<len; ++j) {
			if (++m[s[j]-'a'] == 3) {
				dp[i] += dp[j+1];
				dp[i] %= MOD;
			}
		}
	}
	cout << dp[0]-1 << '\n';

	return 0;
}
