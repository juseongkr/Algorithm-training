#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[2001];
int visit[2001], ans;

void dfs(int n, int d)
{
	if (d == 5) {
		ans = 1;
		return;
	}

	visit[n] = 1;
	for (int i=0; i<graph[n].size(); ++i) {
		int next = graph[n][i];
		if (!visit[next])
			dfs(next, d+1);
	}
	visit[n] = 0;
}

int main()
{
	int n, m, a, b;

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i=0; i<n; ++i) {
		if (!visit[i])
			dfs(i, 1);
		if (ans)
			break;
	}

	if (ans)
		cout << "1\n";
	else
		cout << "0\n";

	return 0;
}
