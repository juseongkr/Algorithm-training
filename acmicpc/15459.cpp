#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 100001

class UnionFind {
public:
	vector<long long> p;
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
		if (x != y) {
			p[x] += p[y];
			p[y] = x;
			return true;
		}
		return false;
	}
};

bool check[MAX];

int main()
{
	vector<pair<int, int>> v;
	long long m;
	int n, f, s;

	cin >> n >> m;
	UnionFind u = UnionFind(n);
	for (int i=0; i<n; ++i) {
		cin >> f >> s;
		u.p[i] = -f;
		v.push_back({s, i});
	}
	sort(v.begin(), v.end());

	for (int i=0; i<n; ++i) {
		int idx = v[i].second;

		check[idx] = true;
		if (idx > 0 && check[idx-1])
			u.uni(idx, idx-1);

		if (idx < n-1 && check[idx+1])
			u.uni(idx, idx+1);

		if (abs(u.p[u.find(idx)]) >= m) {
			cout << v[i].first << '\n';
			break;
		}
	}

	return 0;
}
