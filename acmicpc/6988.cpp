#include <iostream>
#include <cstring>
#include <map>
using namespace std;
#define MAX 3001

int n;
int num[MAX];
long long dp[MAX][MAX];
map<int, int> mp;

long long solve(int a, int b)
{
	if (~dp[a][b])
		return dp[a][b];

	dp[a][b] = 0;
	int next = 2 * num[b] - num[a];
	if (mp.count(next)) {
		int c = mp[next];
		dp[a][b] = max(solve(b, c), (num[b] + num[c]) * 1LL) + num[a];
	}

	return dp[a][b];
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> num[i];
		mp[num[i]] = i;
	}

	long long ans = 0;
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
			ans = max(ans, solve(i, j));

	cout << ans << '\n';

	return 0;
}
