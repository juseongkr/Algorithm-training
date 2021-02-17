#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001

int n, s, d, x, y, cnt;
vector<int> graph[MAX];
int dist[MAX];

int dfs(int cur, int prev)
{
	int ret = 0;
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (next == prev)
			continue;

		ret = max(ret, dfs(next, cur) + 1);
	}

	return dist[cur] = ret;
}

void solve(int cur, int prev)
{
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (next == prev)
			continue;

		if (dist[next] >= d) {
			cnt++;
			solve(next, cur);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> s >> d;
	for (int i=0; i<n-1; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(s, 0);
	solve(s, 0);

	cout << cnt * 2 << '\n';

	return 0;
}
