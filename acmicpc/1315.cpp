#include <iostream>
#include <vector>
using namespace std;

int num[101][3];
int dp[1001][1001];
int visit[101];
int n, a, b;

int solve(int a, int b)
{
	if (dp[a][b] != -1)
		return dp[a][b];

	int cnt = 0, point = 0;
	vector<int> vec;
	for (int i=0; i<n; ++i) {
		if (num[i][0] <= a || num[i][1] <= b) {
			if (!visit[i]) {
				visit[i] = 1;
				vec.push_back(i);
				point += num[i][2];
			}
			cnt++;
		}
	}
	dp[a][b] = cnt;

	for (int i=0; i<=point; ++i) {
		int next_str = min(1000, a + i);
		int next_int = min(1000, b + point - i);
		dp[a][b] = max(dp[a][b], solve(next_str, next_int));
	}

	for (int i=0; i<vec.size(); ++i)
		visit[vec[i]] = 0;

	return dp[a][b];
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i][0] >> num[i][1] >> num[i][2];

	for (int i=0; i<1001; ++i)
		for (int j=0; j<1001; ++j)
			dp[i][j] = -1;

	cout << solve(1, 1) << '\n';

	return 0;
}
