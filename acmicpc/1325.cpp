#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[10001];
vector<pair<int, int>> ans;
int visit[10001];
int cnt;

void dfs(int n)
{
	visit[n] = 1;
	for (int i=0; i<graph[n].size(); ++i) {
		int next= graph[n][i];
		if (!visit[next]) {
			visit[next] = 1;
			cnt++;
			dfs(next);
		}
	}
}

int main()
{
	int n, m, a, b, max_cnt = 0;

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> a >> b;
		graph[b].push_back(a);
	}

	for (int i=1; i<=n; ++i) {
		fill(visit, visit+n+1, 0);
		cnt = 1;
		dfs(i);
		max_cnt = max(max_cnt, cnt);
		ans.push_back({i, cnt});
	}

	for (int i=0; i<ans.size(); ++i)
		if (max_cnt == ans[i].second)
			cout << i+1 << " ";

	return 0;
}
