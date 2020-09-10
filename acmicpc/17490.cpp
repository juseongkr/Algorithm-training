#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <set>
using namespace std;
const int INF = 1e9+7;
typedef tuple<long long, int, int> tp;

int n, m, x, y, z;
long long k;
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

	int getSize(int x)
	{
		return -p[find(x)];
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> k;
	UnionFind uf(n+1);
	for (int i=1; i<=n; ++i) {
		cin >> z;
		vec.push_back({z * 1LL, i, n+1});
	}

	set<pair<int, int>> st;
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		st.insert({x, y});
	}

	for (int i=1; i<=n; ++i) {
		x = i;
		y = i+1 == n+1 ? 1 : i+1;
		if (st.count({x, y}))
			vec.push_back({INF * 1LL, x, y});
		else
			vec.push_back({0LL, x, y});
	}

	sort(vec.begin(), vec.end());

	for (int i=0; i<vec.size(); ++i) {
		auto [z, x, y] = vec[i];
		if (uf.find(x) != uf.find(y)) {
			if (k - z >= 0) {
				k -= z;
				uf.uni(x, y);
			}
		}
	}

	set<int> ans;
	for (int i=1; i<=n; ++i)
		ans.insert(uf.find(i));

	if (ans.size() == 1)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}
