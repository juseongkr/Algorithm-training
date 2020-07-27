#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define MAX 1001
typedef tuple<int, int, int> tp;
const int INF = 1e9+7;

int n, m, k, x, y;
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

int kruskal()
{
	UnionFind u(vec.size());
	int sum = 0, cnt = 0, idx = 0, mi = INF;

	for (int i=0; i<vec.size(); ++i) {
		auto [z, x, y] = vec[i];
		if (z == -1)
			continue;

		if (mi > z) {
			mi = z;
			idx = i;
		}

		if (u.uni(x, y)) {
			sum += z;
			cnt++;
		}
	}
	auto [z, x, y] = vec[idx];
	vec[idx] = {-1, x, y};
	
	return cnt == n-1 ? sum : 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		vec.push_back({i+1, x, y});
	}

	sort(vec.begin(), vec.end());

	while (k--)
		cout << kruskal() << ' ';

	return 0;
}
