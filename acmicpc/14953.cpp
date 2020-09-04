#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001

int n, m, x, y;
int in[MAX], dp[MAX];
vector<int> graph[MAX];

int solve(int cur)
{
	if (~dp[cur])
		return dp[cur];

	dp[cur] = 0;
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (in[cur] < in[next])
			dp[cur] = max(dp[cur], solve(next) + 1);
	}

	return dp[cur];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
		in[x]++;
		in[y]++;
	}

	int ans = 0;
	fill(dp, dp+MAX, -1);
	for (int i=0; i<n; ++i)
		ans = max(ans, solve(i));

	cout << ans + 1 << '\n';

	return 0;
}
