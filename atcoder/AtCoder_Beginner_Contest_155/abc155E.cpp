#include <iostream>
using namespace std;
#define MAX 1000002
#define ll long long
const ll INF = 1e18+7;

string s;
ll num[MAX], sum[MAX], dp[MAX][2];

int main()
{
	cin >> s;
	s = '0' + s;
	int len = s.length();
	for (int i=0; i<len; ++i) {
		num[i] = s[i] - '0';
		sum[i+1] = sum[i] + num[i];
	}

	for (int i=0; i<=len; ++i)
		for (int j=0; j<2; ++j)
			dp[i][j] = INF;

	dp[0][0] = 0;
	for (int i=0; i<len; ++i) {
		dp[i+1][0] = min(dp[i+1][0], dp[i][0] + num[i]);
		dp[i+1][1] = min(dp[i+1][1], dp[i][0] + num[i] + 1);
		dp[i+1][0] = min(dp[i+1][0], dp[i][1] - num[i] + 10);
		dp[i+1][1] = min(dp[i+1][1], dp[i][1] - num[i] + 9);
	}
	cout << dp[len][0] << '\n';

	return 0;
}
