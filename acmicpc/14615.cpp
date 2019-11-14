#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001

int n, m, x, y, k, t;
vector<int> graph[MAX], graph2[MAX];
bool visit[MAX], visit2[MAX];

void dfs(int s)
{
	visit[s] = 1;
	for (int i=0; i<graph[s].size(); ++i) {
		int next = graph[s][i];

		if (!visit[next])
			dfs(next);
	}
}

void dfs2(int s)
{
	visit2[s] = 1;
	for (int i=0; i<graph2[s].size(); ++i) {
		int next = graph2[s][i];

		if (!visit2[next])
			dfs2(next);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph2[y].push_back(x);
	}

	dfs(1);
	dfs2(n);

	cin >> t;
	for (int i=0; i<t; ++i) {
		cin >> k;
		if (visit[k] && visit2[k])
			cout << "Defend the CTP\n";
		else
			cout << "Destroyed the CTP\n";
	}

	return 0;
}
