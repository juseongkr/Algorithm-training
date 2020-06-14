#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;
#define MAX 1001
typedef tuple<double, int, int> tp;

int n;
int x[MAX], y[MAX];

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

inline double dist(int x1, int y1, int x2, int y2)
{
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
	while (1) {
		cin >> n;
		if (n == 0)
			break;

		UnionFind u(n);
		vector<tp> vec;
		for (int i=0; i<n; ++i)
			cin >> x[i] >> y[i];

		for (int i=0; i<n; ++i)
			for (int j=i+1; j<n; ++j)
				vec.push_back({dist(x[i], y[i], x[j], y[j]), i, j});

		sort(vec.begin(), vec.end());

		int cnt = 0;
		double ans = 0;
		for (int i=0; cnt<n-1; ++i) {
			auto [z, x, y] = vec[i];
			if (u.uni(x, y)) {
				ans += z;
				cnt++;
			}
		}
		cout << fixed << setprecision(2) << ans << '\n';
	}

	return 0;
}
