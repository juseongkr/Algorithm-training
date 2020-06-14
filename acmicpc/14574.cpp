#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <tuple>
using namespace std;
#define MAX 1001
#define ll long long
typedef tuple<ll, int, int> tp;

int n;
int x[MAX], y[MAX];
set<int> st[MAX];
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

inline ll dist(int x1, int y1, int x2, int y2)
{
	return (y1+y2)/abs(x1-x2);
}

int main()
{
	cin >> n;
	UnionFind u(n);
	for (int i=0; i<n; ++i)
		cin >> x[i] >> y[i];

	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
			vec.push_back({dist(x[i], y[i], x[j], y[j]), i, j});

	sort(vec.rbegin(), vec.rend());

	ll ans = 0;
	int cnt = 0;
	for (int i=0; cnt<n-1; ++i) {
		auto [z, x, y] = vec[i];
		if (u.uni(x, y)) {
			st[x].insert(y);
			st[y].insert(x);
			ans += 1LL*z;
			cnt++;
		}
	}

	cout << ans << '\n';

	while (cnt--) {
		for (int i=0; i<n; ++i) {
			if (st[i].size() == 1) {
				int j = *st[i].begin();
				cout << j+1 << " " << i+1 << '\n';
				st[j].erase(i);
				st[i].erase(j);
				break;
			}
		}
	}

	return 0;
}
