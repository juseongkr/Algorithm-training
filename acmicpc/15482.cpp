#include <iostream>
using namespace std;
#define MAX 1001

string s1, s2;
int dp[MAX*3][MAX*3];

int main()
{	
	cin >> s1 >> s2;
	for (int i=3; i<=s1.length(); i+=3) {
		for (int j=3; j<=s2.length(); j+=3) {
			if (s1.substr(i-3, 3) == s2.substr(j-3, 3))
				dp[i][j] = dp[i-3][j-3] + 1;
			else
				dp[i][j] = max(dp[i-3][j], dp[i][j-3]);
		}
	}

	cout << dp[s1.length()][s2.length()] << '\n';

	return 0;
}
