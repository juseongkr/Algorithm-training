#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> ti;
const int MOD = 1e9;

long long total;
int n, m, x, y, z;
vector<ti> vec;

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

	long long size(int x) { return -p[find(x)]; }
};

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >>  m;
	UnionFind u(n);
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		vec.push_back({z, x, y});
		total += z;
	}

	sort(vec.begin(), vec.end());

	long long ans = 0;
	for (int i=m-1; i>=0; i--) {
		auto [z, x, y] = vec[i];
		long long a = u.size(x);
		long long b = u.size(y);
		if (u.uni(x, y)) {
			long long val = (a * b) % MOD;
			val = (val * total) % MOD;
			ans = (ans + val) % MOD;
		}
		total -= z;
	}
	cout << ans << '\n';

	return 0;
}
