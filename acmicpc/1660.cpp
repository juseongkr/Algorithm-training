#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define MAX 300001

int dp[MAX];

int main()
{
	vector<int> bomb;
	int n, cnt = 1;

	bomb.push_back(1);
	for (int i=2; ; ++i) {
		cnt += (i * (i+1) / 2);
		bomb.push_back(cnt);
		if (cnt >= MAX)
			break;
	}

	cin >> n;
	fill(dp+1, dp+MAX, INT_MAX);
	for (int i=0; i<bomb.size(); ++i)
		for (int j=bomb[i]; j<=n; ++j)
			dp[j] = min(dp[j], dp[j-bomb[i]] + 1);

	cout << dp[n] << '\n';

	return 0;
}
