#include <iostream>
#include <queue>
using namespace std;
#define MAX 10001

vector<int> graph[MAX];
int dp[MAX], in[MAX], cost[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, c, m, a;

	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> cost[i] >> m;
		for (int j=0; j<m; ++j) {
			cin >> a;
			graph[a].push_back(i);
			in[i]++;
		}
	}

	queue<int> que;
	for (int i=1; i<=n; ++i) {
		if (in[i] == 0) {
			que.push(i);
			dp[i] = cost[i];
		}
	}

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];

			dp[next] = max(dp[next], dp[cur] + cost[next]);
			if (--in[next] == 0)
				que.push(next);
		}
	}

	
	int ans = 0;
	for (int i=1; i<=n; ++i)
		ans = max(ans, dp[i]);

	cout << ans << '\n';

	return 0;
}
