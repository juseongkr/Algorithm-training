#include <iostream>
#include <cstring>
using namespace std;
#define MAX 301

int n, m, k, t, a, b;
int num[MAX], dp[MAX][MAX][MAX];

int solve(int cur, int use, int left)
{
	if (cur == n)
		return 0;

	int &ret = dp[cur][use][left];
	if (~ret)
		return ret;

	if (num[cur] >= t)
		use = 0;

	ret = solve(cur+1, use, left);
	if (0 < left && num[cur] + use < t)
		ret = max(ret, solve(cur, use+1, left-1));

	if (num[cur] + use >= t)
		ret++;

	return ret;
}

int main()
{
	cin >> n >> m >> k >> t;
	for (int i=0; i<m; ++i) {
		cin >> a >> b;
		for (int j=a-1; j<b-1; ++j)
			num[j]++;
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0, k) << '\n';

	return 0;
}
