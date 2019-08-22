#include <iostream>
using namespace std;
#define MAX 51
const int INF = 1e9+7;

int n;
int num[MAX];
int dp[MAX][500001];

int solve(int i, int d)
{
	if (i == n) {
		if (d == 0)
			return 0;
		else
			return -INF;
	}

	if (dp[i][abs(d)] != 0)
		return dp[i][abs(d)];

	dp[i][abs(d)] = max(solve(i+1, d), max(solve(i+1, d + num[i]) + num[i], solve(i+1, d - num[i]) + num[i]));

	return dp[i][abs(d)];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	int ans = solve(0, 0);
	if (ans)
		cout << ans/2 << '\n';
	else
		cout << "-1\n";

	return 0;
}
