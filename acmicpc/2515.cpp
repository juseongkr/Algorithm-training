#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 300001

int dp[MAX];
int n, s, h, c;
vector<pair<int, int>> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> s;
	for (int i=0; i<n; ++i) {
		cin >> h >> c;
		vec.push_back({h, c});
	}

	sort(vec.begin(), vec.end());

	dp[0] = vec[0].second;

	int ans = dp[0];
	int high = 0, idx = 0;
	for (int i=1; i<n; ++i) {
		while (s + vec[idx].first <= vec[i].first)
			high = max(high, dp[idx++]);

		dp[i] = vec[i].second + high;
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';

	return 0;
}
