#include <iostream>
#include <cstring>
using namespace std;
#define MAX 2001

int n, m, x, y;
int num[MAX], dp[MAX][MAX];

bool solve(int a, int b)
{
	if (a == b)
		return 1;

	if (dp[a][b] != 0)
		return dp[a][b];

	if (a + 1 == b) {
		if (num[a] == num[b])
			dp[a][b] = 1;
		else
			dp[a][b] = 0;
	} else {
		if (num[a] == num[b])
			dp[a][b] = solve(a+1, b-1);
	}
	return dp[a][b];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i=1; i<=n; ++i)
		cin >> num[i];
	cin >> m;

	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		cout << solve(x, y) << '\n';
	}

	return 0;
}
