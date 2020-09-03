#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> tp;

int n, q, x1, x2, y;
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

	cin >> n >> q;
	UnionFind uf(n);
	for (int i=0; i<n; ++i) {
		cin >> x1 >> x2 >> y;
		vec.push_back({x1, x2, i+1});
	}

	sort(vec.begin(), vec.end());

	for (int i=1; i<n; ++i) {
		auto [x, y, a] = vec[i-1];
		auto [u, v, b] = vec[i];

		if (u <= y) {
			uf.uni(a, b);
			get<1>(vec[i]) = max(get<1>(vec[i]), get<1>(vec[i-1]));
		}
	}

	while (q--) {
		cin >> x1 >> x2;
		if (uf.find(x1) == uf.find(x2))
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}
