#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 3001

int n, t, h;
int cost[MAX], dp[MAX];

int main()
{
	cin >> n;
	for (int i=1; i<=n; ++i)
		cin >> cost[i];
	cin >> t >> h;

	sort(cost+1, cost+n+1);

	for (int i=1; i<=n; ++i) {
		dp[i] = dp[i-1] + cost[i] * t;
		int val = h;
		for (int j=i; j>0; j--) {
			val += (cost[(i+j+1)/2] - cost[j]) * t;
			dp[i] = min(dp[i], dp[j-1] + val);
		}
	}
	cout << dp[n] << '\n';

	return 0;
}
