#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define MAX 401
typedef tuple<double, int, int, double, double> tp;
const double INF = 1e10;
const double MIN = 1e-9;

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

vector<tp> vec;
int n, m, f, u, v;
double c, t;

bool check(double mid)
{
	for (int i=0; i<m; ++i) {
		auto [cost, u, v, c, t] = vec[i];
		get<0>(vec[i]) = mid * t + c;
	}

	sort(vec.begin(), vec.end());

	UnionFind uf(n);
	double sum = 0.0;
	for (int i=0; i<m; ++i) {
		auto [cost, u, v, c, f] = vec[i];
		if (uf.uni(u, v))
			sum += cost;
	}

	return sum > f;
}

int main()
{
	cin >> n >> m >> f;
	for (int i=0; i<m; ++i) {
		cin >> u >> v >> c >> t;
		vec.push_back({0.0, u, v, c, t});
	}

	double l = 0.0, r = INF;
	while (r - l > MIN) {
		double mid = (l+r)/2.0;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	cout << fixed << setprecision(4) << l << '\n';

	return 0;
}
