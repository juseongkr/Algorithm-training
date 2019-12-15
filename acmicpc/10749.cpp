#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define MAX 2001

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

int n, k, cnt;
int id[MAX];
vector<tuple<int, int, int>> vec;

int main()
{
	cin >> n;
	UnionFind u = UnionFind(n);
	for (int i=0; i<n; ++i) {
		cin >> id[i];
		for (int j=0; j<i; ++j)
			vec.push_back({id[i] ^ id[j], i, j});
	}

	sort(vec.rbegin(), vec.rend());

	long long ans = 0;
	for (int i=0; i<vec.size(); ++i) {
		auto [z, x, y] = vec[i];
		if (u.uni(x, y)) {
			ans += z;
			if (++cnt == n-1)
				break;
		}
	}
	cout << ans << '\n';

	return 0;
}
