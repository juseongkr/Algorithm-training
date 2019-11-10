#include <iostream>
#include <vector>
using namespace std;
#define MAX 3001

bool flag;
int v, e, x, y;
int visit[MAX][MAX];
vector<int> graph[MAX];

void dfs(int prev, int cur, int cnt)
{
	if (cnt == e) {
		flag = true;
		return;
	}

	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];

		if (visit[cur][next] == prev || visit[next][cur] == prev)
			continue;

		visit[cur][next] = visit[next][cur] = prev;
		dfs(prev, next, cnt+1);
	}
}

int main()
{
	cin >> v >> e;
	for (int i=0; i<e; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (int i=1; i<=v; ++i) {
		dfs(i, i, 0);
		if (flag)
			break;
	}

	if (flag)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}
