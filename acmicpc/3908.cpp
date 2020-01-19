#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 1122

int t, n, k;
bool check[MAX];
int dp[200][15][MAX];
vector<int> prime;

int solve(int cur, int cnt, int num)
{
	if (num == 0 && cnt == 0)
		return 1;

	if (cur == prime.size() || cnt == 0)
		return 0;

	if (~dp[cur][cnt][num])
		return dp[cur][cnt][num];

	dp[cur][cnt][num] = solve(cur+1, cnt, num);
	if (num >= prime[cur])
		dp[cur][cnt][num] += solve(cur+1, cnt-1, num - prime[cur]);

	return dp[cur][cnt][num];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));
	fill(check+2, check+MAX, 1);
	for (int i=2; i<=MAX; ++i) {
		if (check[i])
			prime.push_back(i);
		for (int j=i; j<=MAX; j+=i)
			check[j] = 0;
	}

	cin >> t;
	while (t--) {
		cin >> n >> k;
		cout << solve(0, k, n) << '\n';
	}

	return 0;
}
