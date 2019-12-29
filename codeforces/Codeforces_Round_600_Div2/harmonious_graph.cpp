#include <iostream>
#include <vector>
using namespace std;
#define MAX 200001

int n, m, x, y, mx, mi, ans;
vector<int> graph[MAX];
int visit[MAX];

void dfs(int u)
{
	visit[u] = 1;
	mi = min(mi, u);
	mx = max(mx, u);
	for (int i=0; i<graph[u].size(); ++i) {
		int next = graph[u][i];
		if (!visit[next])
			dfs(next);
	}
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	mi = 1e9+7, mx = -1e9+7;
	for (int i=1; i<=n; ++i) {
		if (!visit[i]) {
			if (mi <= i && i <= mx)
				ans++;
			dfs(i);
		}
	}
	cout << ans << '\n';

	return 0;
}
