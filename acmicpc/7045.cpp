#include <iostream>
#include <vector>
using namespace std;
#define MAX 10001

int n, x, y;
vector<int> graph[MAX];
bool visit[MAX];
int dp[MAX];

int dfs(int cur)
{
	visit[cur] = 1;
	int cnt = 1, mx = 0;
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (!visit[next]) {
			int temp = dfs(next);
			mx = max(mx, temp);
			cnt += temp;
		}
	}

	dp[cur] = max(mx, n-cnt);
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	fill(dp, dp+MAX, -1);
	for (int i=0; i<n-1; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(1);

	bool flag = false;
	for (int i=1; i<=n; ++i) {
		if (dp[i] <= n/2) {
			cout << i << '\n';
			flag = true;
		}
	}

	if (!flag)
		cout << "NONE\n";

	return 0;
}
