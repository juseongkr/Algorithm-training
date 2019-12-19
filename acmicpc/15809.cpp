#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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

	bool uni(int x, int y, int sign)
	{
		if (sign)
			sign = -1;
		else
			sign = 1;
		x = find(x);
		y = find(y);
		if (x == y)
			return false;
		if (p[x] <= p[y]) {
			p[x] += p[y] * sign;
			p[y] = x;
			return true;
		} else {
			p[y] += p[x] * sign;
			p[x] = y;
			return true;
		}
		return false;
	}
};

int main()
{
	int n, m, a, o, p, q;

	cin >> n >> m;
	UnionFind u = UnionFind(n);
	for (int i=0; i<n; ++i) {
		cin >> a;
		u.p[i] = -a;
	}

	for (int i=0; i<m; ++i) {
		cin >> o >> p >> q;
		o--;
		p--;
		q--;
		u.uni(p, q, o);
	}

	vector<int> vec;
	for (int i=0; i<n; ++i)
		if (u.p[i] < 0)
			vec.push_back(-u.p[i]);

	sort(vec.begin(), vec.end());

	cout << vec.size() << '\n';
	for (int i=0; i<vec.size(); ++i)
		cout << vec[i] << ' ';

	return 0;
}
