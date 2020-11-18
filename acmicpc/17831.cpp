#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 200001

int n, x;
int val[MAX], dp[MAX][2];
vector<int> graph[MAX];

int solve(int cur, bool boss)
{
	if (~dp[cur][boss])
		return dp[cur][boss];

	int sum = 0;
	dp[cur][boss] = 0;
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		sum += max(solve(next, 0), solve(next, 1));
	}

	dp[cur][boss] = sum;
	if (boss) {
		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];
			int temp = max(solve(next, 0), solve(next, 1));

			dp[cur][boss] = max(dp[cur][boss], \
					sum - temp + solve(next, 0) + val[cur] * val[next]);
		}
	}

	return dp[cur][boss];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<n; ++i) {
		cin >> x;
		graph[--x].push_back(i);
	}

	for (int i=0; i<n; ++i) {
		cin >> val[i];

	}

	memset(dp, -1, sizeof(dp));
	cout << max(solve(0, 0), solve(0, 1)) << '\n';

	return 0;
}
