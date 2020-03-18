#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 10001

int n, x, y;
bool visit[MAX];
int val[MAX], dp[MAX][2];
vector<int> graph[MAX], tree[MAX], ans;

void dfs(int cur)
{
	visit[cur] = 1;
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (!visit[next]) {
			tree[cur].push_back(next);
			dfs(next);
		}
	}
}

int solve(int cur, bool ok)
{
	if (cur == n)
		return 0;

	if (~dp[cur][ok])
		return dp[cur][ok];

	dp[cur][ok] = ok ? val[cur] : 0;
	for (int i=0; i<tree[cur].size(); ++i) {
		int next = tree[cur][i];
		int cost = solve(next, false);
		if (!ok)
			cost = max(cost, solve(next, true));
		dp[cur][ok] += cost;
	}

	return dp[cur][ok];
}

void tracking(int cur, bool ok)
{
	if (ok) {
		ans.push_back(cur);
		for (int i=0; i<tree[cur].size(); ++i) {
			int next = tree[cur][i];
			tracking(next, false);
		}
	} else {
		for (int i=0; i<tree[cur].size(); ++i) {
			int next = tree[cur][i];
			if (dp[next][true] < dp[next][false])
				tracking(next, false);
			else
				tracking(next, true);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> val[i];

	for (int i=0; i<n-1; ++i) {
		cin >> x >> y;
		x--;
		y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(0);

	memset(dp, -1, sizeof(dp));
	int l = solve(0, 1);
	int r = solve(0, 0);
	if (l > r)
		tracking(0, 1);
	else
		tracking(0, 0);

	cout << max(l, r) << '\n';
	sort(ans.begin(), ans.end());
	for (const auto i : ans)
		cout << i+1 << " ";

	return 0;
}
