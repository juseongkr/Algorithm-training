#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001
#define DEP 18

vector<int> graph[MAX];
int in[MAX], out[MAX];
int p[MAX][DEP];
int u, v, idx;

void dfs(int cur, int prev)
{
	in[cur] = ++idx;
	p[cur][0] = prev;
	for (int i=1; i<DEP; ++i)
		p[cur][i] = p[p[cur][i-1]][i-1];

	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (next != prev)
			dfs(next, cur);
	}
	out[cur] = ++idx;
}

bool upper(int u, int v)
{
	return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v)
{
	if (upper(u, v))
		return u;
	if (upper(v, u))
		return v;

	for (int i=DEP-1; i>=0; i--)
		if (!upper(p[u][i], v))
			u = p[u][i];
	return p[u][0];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;

	cin >> n;
	for (int i=0; i<n-1; ++i) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1, 1);

	cin >> m;
	while (m--) {
		cin >> u >> v;
		cout << lca(u, v) << '\n';
	}

	return 0;
}
