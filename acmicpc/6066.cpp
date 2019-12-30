#include <iostream>
using namespace std;
const int INF = 1e9+7;
#define MAX 60001

int n, h, w, c;
int dp[MAX];

int main()
{
	cin >> n >> h;
	fill(dp+1, dp+MAX, INF);
	for (int i=0; i<n; ++i) {
		cin >> w >> c;
		for (int j=0; j<h; ++j)
			dp[w+j] = min(dp[w+j], dp[j] + c);
	}

	int ans = INF;
	for (int i=h; i<MAX; ++i)
		ans = min(ans, dp[i]);

	cout << ans << '\n';

	return 0;
}
