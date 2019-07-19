#include <iostream>
#include <cstring>
using namespace std;
#define MAX 5001

int n;
double m, p;
int cal[MAX], pri[MAX];
int dp[10001];

int solve(int val)
{
	if (dp[val] != -1)
		return dp[val];

	dp[val] = 0;
	for (int i=0; i<n; ++i)
		if (val - pri[i] >= 0)
			dp[val] = max(dp[val], solve(val - pri[i]) + cal[i]);

	return dp[val];
}

int main()
{
	while (1) {
		cin >> n >> m;
		if (n == 0 and m == 0.00)
			break;

		for (int i=0; i<n; ++i) {
			cin >> cal[i] >> p;
			pri[i] = int(p * 100 + 0.5);
		}

		memset(dp, -1, sizeof(dp));
		cout << solve(int(m * 100 + 0.5)) << '\n';
	}

	return 0;
}
