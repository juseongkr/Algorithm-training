#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> tp;

int n, k, cost, cnt;
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

	cin >> n;
	UnionFind uf(n);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> k;
			if (i >= j)
				continue;
			if (k > 0) {
				vec.push_back({k, i, j});
			} else {
				cnt++;
				cost += -k;
				uf.uni(i, j);
			}
		}
	}

	sort(vec.begin(), vec.end());

	vector<pair<int, int>> ans;
	for (int i=0; i<vec.size() && cnt < n-1; ++i) {
		auto [z, x, y] = vec[i];
		if (uf.uni(x, y)) {
			cost += z;
			ans.push_back({x, y});
		}
	}

	cout << cost << " " << ans.size() << '\n';
	for (int i=0; i<ans.size(); ++i) {
		auto [x, y] = ans[i];
		cout << x+1 << " " << y+1 << '\n';
	}

	return 0;
}
