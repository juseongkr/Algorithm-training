#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define MAX 1001
typedef tuple<int, int, int> tp;

int n, x, y, z, k, mx, far;
vector<pair<int, int>> graph[MAX];
bool visit[MAX];
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

void dfs(int cur, int cost)
{
	if (visit[cur])
		return;
	visit[cur] = 1;

	if (mx < cost) {
		mx = cost;
		far = cur;
	}

	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i].first;
		int next_cost = graph[cur][i].second + cost;

		dfs(next, next_cost);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<k; ++i) {
		cin >> x >> y >> z;
		vec.push_back({z, x, y});
	}

	sort(vec.begin(), vec.end());

	UnionFind uf(n);
	int ans = 0, cnt = 0;
	for (int i=0; i<vec.size(); ++i) {
		auto [z, x, y] = vec[i];
		if (uf.uni(x, y)) {
			graph[x].push_back({y, z});
			graph[y].push_back({x, z});
			ans += z;
			if (++cnt == n-1)
				break;
		}
	}

	cout << ans << '\n';

	dfs(0, 0);
	fill(visit, visit+n, 0);
	dfs(far, 0);

	cout << mx << '\n';

	return 0;
}
