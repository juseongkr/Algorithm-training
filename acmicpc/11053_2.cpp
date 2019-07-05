#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001

int main()
{
	int num[MAX], dp[MAX];
	int n, ans = 0;

	cin >> n;
	fill(dp, dp+MAX, 1);
	for (int i=0; i<n; ++i)
		cin >> num[i];

	for (int i=0; i<n; ++i) {
		for (int j=0; j<i; ++j) {
			if (num[i] > num[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';

	return 0;
}
