#include <iostream>
using namespace std;
#define MAX 1001
#define INF 10001

int dp[MAX];

int main()
{
	int c[MAX];
	int n;

	cin >> n;
	for (int i=1; i<=n; ++i)
		cin >> c[i];

	fill(dp+1, dp+MAX, INF);
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=i; ++j)
			dp[i] = min(dp[i], dp[i-j] + c[j]);

	cout << dp[n] << '\n';

	return 0;
}
