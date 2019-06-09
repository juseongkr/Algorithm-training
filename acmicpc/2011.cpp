#include <iostream>
using namespace std;
#define MAX 5001
#define MOD 1000000

int dp[MAX];

int main()
{
	string s;

	cin >> s;
	if (s == "0") {
		cout << "0\n";
		return 0;
	}

	dp[0] = 1;
	for (int i=1; i<=s.length(); ++i) {
		int one = s[i-1]-'0';
		int two = (s[i-2]-'0')*10 + s[i-1]-'0';

		if (1 <= one && one <= 9)
			dp[i] = (dp[i] + dp[i-1]) % MOD;

		if (i == 1)
			continue;

		if (10 <= two && two <= 26)
			dp[i] = (dp[i] + dp[i-2]) % MOD;
	}

	cout << dp[s.length()] << '\n';

	return 0;
}
