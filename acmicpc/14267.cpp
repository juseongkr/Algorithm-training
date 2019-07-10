#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001

int n, m, a, b;
int ans[MAX];
vector<int> graph[MAX];

void dfs(int n)
{
	for (int i=0; i<graph[n].size(); ++i) {
		int next = graph[n][i];
		ans[next] += ans[n];
		dfs(next);
	}
}

int main()
{
	cin >> n >> m >> a;
	for (int i=2; i<=n; ++i) {
		cin >> a;
		graph[a].push_back(i);
	}

	for (int i=0; i<m; ++i) {
		cin >> a >> b;
		ans[a] += b;
	}

	dfs(1);

	for (int i=1; i<=n; ++i)
		cout << ans[i] << " ";

	return 0;
}
