#include <iostream>
using namespace std;
#define MAX 1000001

long long dp[MAX], s[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int t, n;

	fill(dp, dp+MAX, 1);
	for (int i=2; i<MAX; ++i)
		for (int j=1; i*j<MAX; ++j)
			dp[i*j] += i;

	for (int i=1; i<MAX; ++i)
		s[i] = s[i-1] + dp[i];

	cin >> t;
	while (t--) {
		cin >> n;

		cout << s[n] << '\n';
	}

	return 0;
}
