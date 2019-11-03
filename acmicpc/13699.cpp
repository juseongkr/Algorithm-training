#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 36

ll dp[MAX], n;

ll t(ll k)
{
	if (k <= 0)
		return 1;

	if (dp[k] != -1)
		return dp[k];

	dp[k] = 0;
	for (int i=0; i<k; ++i)
		dp[k] += t(i) * t(k-i-1);

	return dp[k];
}

int main()
{
	cin >> n;

	memset(dp, -1, sizeof(dp));
	cout << t(n) << '\n';

	return 0;
}
