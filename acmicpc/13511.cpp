#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001
#define DEP 21
#define ll long long

ll n, m, a, b, c, op, k;
vector<pair<ll, ll>> graph[MAX];
ll parent[MAX][DEP];
ll depth[MAX], dist[MAX];

void dfs(ll cur, ll prev, ll val)
{
	depth[cur] = depth[prev] + 1;
	parent[cur][0] = prev;
	dist[cur] = val;
	for (int i=1; i<DEP; ++i)
		parent[cur][i] = parent[parent[cur][i-1]][i-1];

	for (int i=0; i<graph[cur].size(); ++i) {
		ll next = graph[cur][i].first;
		ll cost = graph[cur][i].second;
		if (next != prev)
			dfs(next, cur, cost + val);
	}
}

ll lca(ll a, ll b)
{
	if (depth[a] > depth[b])
		swap(a, b);

	for (int i=DEP-1; i>=0; i--)
		if (depth[a] <= depth[parent[b][i]])
			b = parent[b][i];

	ll ret = a;
	if (a != b) {
		for (int i=DEP-1; i>=0; i--) {
			if (parent[a][i] && parent[a][i] != parent[b][i]) {
				a = parent[a][i];
				b = parent[b][i];
			}
		}
		ret = parent[a][0];
	}
	return ret;
}

ll getK(ll a, ll b, ll k)
{
	ll l = lca(a, b);
	ll diff = depth[a] - depth[l];
	k--;
	if (diff >= k) {
		for (int i=0; k; ++i) {
			if (k % 2 == 1)
				a = parent[a][i];
			k /= 2;
		}
		return a;
	}

	k = depth[b] - depth[l] + diff - k;
	for (int i=0; k; ++i) {
		if (k % 2 == 1)
			b = parent[b][i];
		k /= 2;
	}
	return b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i=0; i<n-1; ++i) {
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	dfs(1, 0, 0);

	cin >> m;
	for (int i=0; i<m; ++i) {
		cin >> op;
		if (op == 1) {
			cin >> a >> b;
			cout << dist[a] + dist[b] - 2 * dist[lca(a, b)] << '\n';
		} else {
			cin >> a >> b >> k;
			cout << getK(a, b, k) << '\n';
		}
	}
	return 0;
}
