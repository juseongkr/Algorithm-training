#include <iostream>
using namespace std;
#define MAX 1001

int num[MAX], dp[MAX], dp2[MAX];

int main()
{
	int n, t, ans = 0;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> num[i];
		dp[i] = dp2[i] = 1;
	}

	for (int i=0; i<n; ++i)
		for (int j=0; j<i; ++j)
			if (num[i] > num[j])
				dp[i] = max(dp[i], dp[j] + 1);

	for (int i=n-1; i>=0; i--)
		for (int j=n-1; j>i; j--)
			if (num[i] > num[j])
				dp2[i] = max(dp2[i], dp2[j] + 1);

	for (int i=0; i<n; ++i)
		ans = max(ans, dp[i] + dp2[i] - 1);

	cout << ans << '\n';
	
	return 0;
}
