#include <iostream>
using namespace std;

string s;
long long dp[26][26], dict[26];

int main()
{
	cin >> s;
	for (int i=0; i<s.length(); ++i) {
		for (int j=0; j<26; ++j)
			dp[j][s[i]-'a'] += dict[j];
		dict[s[i]-'a']++;
	}

	long long ans = 0;
	for (int i=0; i<26; ++i)
		ans = max(ans, dict[i]);

	for (int i=0; i<26; ++i)
		for (int j=0; j<26; ++j)
			ans = max(ans, dp[i][j]);

	cout << ans << '\n';

	return 0;
}
