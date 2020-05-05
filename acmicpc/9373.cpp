#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;
#define MAX 1001
typedef tuple<double, int, int> tp;

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

double dist(int x1, int y1, int x2, int y2)
{
	return sqrt(1LL*(x1-x2)*(x1-x2) + 1LL*(y1-y2)*(y1-y2));
}

int T, w, n;
int x[MAX], y[MAX], r[MAX];

int main()
{
	cin >> T;
	while (T--) {
		vector<tp> vec;
		UnionFind u(MAX);
		cin >> w >> n;
		for (int i=0; i<n; ++i)
			cin >> x[i] >> y[i] >> r[i];

		int L = n, R = n+1;
		vec.push_back({w, L, R});
		for (int i=0; i<n; ++i) {
			vec.push_back({max(0, x[i]-r[i]), i, L});
			vec.push_back({max(0, w-x[i]-r[i]), i, R});
			for (int j=i+1; j<n; ++j) {
				double d = dist(x[i], y[i], x[j], y[j]);
				vec.push_back({max(0.0, d-r[i]-r[j]), i, j});
			}
		}

		sort(vec.begin(), vec.end());
		for (int i=0; i<vec.size(); ++i) {
			auto [z, x, y] = vec[i];
			if (u.uni(x, y)) {
				if (u.find(L) == u.find(R)) {
					cout << fixed << setprecision(6) << z/2 << '\n';
					break;
				}
			}
		}
	}

	return 0;
}
