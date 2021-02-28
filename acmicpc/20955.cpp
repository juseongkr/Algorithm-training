#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001

int n, m, x, y, cnt;
vector<int> graph[MAX];
bool visit[MAX];

class UnionFind {
public:
	vector<int> p;
	UnionFind(int n) { p.resize(n+1, -1); }
	int find(int x)
	{
		if (p[x] < 0)
			return x;
		return p[x] = find(p[x]);
	}

	bool uni(int x, int y)
	{
		x = find(x);
		y = find(y);
		if (x == y)
			return false;
		if (p[x] < p[y])
			swap(x, y);
		p[y] += p[x];
		p[x] = y;
		return true;
	}
};

void dfs(int cur)
{
	if (visit[cur])
		return;

	visit[cur] = 1;
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		dfs(next);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	UnionFind uf(n);
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		if (uf.uni(x, y)) {
			graph[x].push_back(y);
			graph[y].push_back(x);
		} else {
			cnt++;
		}
	}

	for (int i=1; i<=n; ++i) {
		if (!visit[i]) {
			dfs(i);
			cnt++;
		}
	}

	cout << cnt-1 << '\n';

	return 0;
}
