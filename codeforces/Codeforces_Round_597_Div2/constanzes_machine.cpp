#include <iostream>
using namespace std;
#define MAX 100001
const int MOD = 1e9+7;

int n;
string s;
int dp[MAX];

int main()
{
	cin >> s;
	n = s.length();
	for (int i=0; i<n; ++i) {
		if (s[i] == 'w' || s[i] == 'm') {
			cout << "0\n";
			return 0;
		}
	}

	dp[0] = dp[1] = 1;
	for (int i=1; i<n; ++i) {
		if ((s[i] == 'u' && s[i-1] == 'u') || (s[i] == 'n' && s[i-1] == 'n'))
			dp[i+1] = (dp[i] + dp[i-1]) % MOD;
		else
			dp[i+1] = dp[i];
	}

	cout << dp[n] << '\n';

	return 0;
}
