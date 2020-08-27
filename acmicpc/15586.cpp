#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define MAX 100001
typedef tuple<int, int, int> tp;

int n, q, k, x, y, z;
vector<tp> vec, query;
int ans[MAX];

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

	int sz(int x)
	{
		return -p[find(x)];
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> q;
	UnionFind uf(n);
	for (int i=0; i<n-1; ++i) {
		cin >> x >> y >> z;
		vec.push_back({z, x, y});
	}

	for (int i=0; i<q; ++i) {
		cin >> k >> x;
		query.push_back({k, x, i});
	}

	sort(vec.rbegin(), vec.rend());
	sort(query.rbegin(), query.rend());

	for (int i=0, j=0; i<query.size(); ++i) {
		auto [k, x, idx] = query[i];
		for (; j<vec.size(); ++j) {
			if (k > get<0>(vec[j]))
				break;
			auto [w, u, v] = vec[j];
			uf.uni(u, v);
		}
		ans[idx] = uf.sz(x);
	}

	for (int i=0; i<q; ++i)
		cout << ans[i]-1 << '\n';

	return 0;
}
