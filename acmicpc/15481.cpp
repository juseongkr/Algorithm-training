#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define MAX 200001
#define DEP 20
typedef tuple<int, int, int, int> tp;
typedef pair<int, int> pi;

int n, m, x, y, z;
long long ans[MAX];
int depth[MAX];
pi parent[MAX][DEP];
vector<pi> graph[MAX];
vector<tp> vec;

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

void dfs(int cur, int prev, int val)
{
	depth[cur] = depth[prev] + 1;
	parent[cur][0] = {prev, val};
	for (int i=1; i<DEP; ++i) {
		auto [p, v] = parent[cur][i-1];
		parent[cur][i] = {parent[p][i-1].first, max(v, parent[p][i-1].second)};
	}

	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i].first;
		int cost = graph[cur][i].second;
		if (next != prev)
			dfs(next, cur, cost);
	}
}

int lca_max(int u, int v)
{
	if (depth[u] > depth[v])
		swap(u, v);

	int ret = 0;
	for (int i=DEP-1; i>=0; i--) {
		if (depth[u] <= depth[parent[v][i].first]) {
			ret = max(ret, parent[v][i].second);
			v = parent[v][i].first;
		}
	}

	if (u != v) {
		for (int i=DEP-1; i>=0; i--) {
			if (parent[u][i].first != 0 && parent[u][i].first != parent[v][i].first) {
				ret = max(ret, parent[u][i].second);
				ret = max(ret, parent[v][i].second);
				u = parent[u][i].first;
				v = parent[v][i].first;
			}
		}
		ret = max(ret, parent[u][0].second);
		ret = max(ret, parent[v][0].second);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	UnionFind u(n);
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		vec.push_back({z, x, y, i});
	}

	sort(vec.begin(), vec.end());

	int cnt = 0;
	long long mst = 0;
	for (int i=0; i<m; ++i) {
		auto [z, x, y, _] = vec[i];
		if (u.uni(x, y)) {
			mst += z;
			graph[x].push_back({y, z});
			graph[y].push_back({x, z});
			if (++cnt == n-1)
				break;
		}
	}

	dfs(1, 0, 0);

	for (int i=0; i<m; ++i) {
		auto [z, x, y, idx] = vec[i];
		ans[idx] = mst + z - lca_max(x, y);
	}

	for (int i=0; i<m; ++i)
		cout << ans[i] << '\n';

	return 0;
}
