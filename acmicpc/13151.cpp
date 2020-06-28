#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> tp;

int n, m, l, x, y, z, built;
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

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> l;
	UnionFind uf(n);
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		if (i < l)
			built += z;
		vec.push_back({z, x, y});
	}

	sort(vec.begin(), vec.end());

	int sum = 0, cnt = 0;
	for (int i=0; i<vec.size(); ++i) {
		auto [z, x, y] = vec[i];
		if (uf.uni(x, y)) {
			sum += z;
			cnt++;
		}
	}

	if (cnt != n-1 || sum > built)
		cout << "impossible\n";
	else
		cout << "possible\n";

	return 0;
}
