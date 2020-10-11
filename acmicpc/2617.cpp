#include <iostream>
#include <vector>
using namespace std;
#define MAX 100

int n, m, x, y;
bool visit[MAX];
vector<int> go[MAX], back[MAX];

int dfs1(int cur)
{
	if (visit[cur])
		return 0;
	visit[cur] = 1;

	int ret = 1;
	for (int i=0; i<go[cur].size(); ++i) {
		int next = go[cur][i];
		ret += dfs1(next);
	}

	return ret;
}

int dfs2(int cur)
{
	if (visit[cur])
		return 0;
	visit[cur] = 1;

	int ret = 1;
	for (int i=0; i<back[cur].size(); ++i) {
		int next = back[cur][i];
		ret += dfs2(next);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		go[x].push_back(y);
		back[y].push_back(x);
	}

	int ans = 0;
	for (int i=1; i<=n; ++i) {
		fill(visit, visit+n+1, 0);
		if (dfs1(i) > n/2+1) {
			ans++;
		} else {
			fill(visit, visit+n+1, 0);
			if (dfs2(i) > n/2+1)
				ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}
