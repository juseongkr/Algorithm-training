#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define MAX 10001
const int INF = 1e9+7;
typedef tuple<int, int, int> tp;

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

int cost[MAX];
int n, p, x, y, z;
vector<tp> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> p;
	int ans = INF;
	for (int i=1; i<=n; ++i) {
		cin >> cost[i];
		ans = min(cost[i], ans);
	}

	while (p--) {
		cin >> x >> y >> z;
		vec.push_back({cost[x] + cost[y] + z * 2, x, y});
	}

	sort(vec.begin(), vec.end());

	int cnt = 0;
	UnionFind uf(n);
	for (int i=0; i<vec.size(); ++i) {
		auto [z, x, y] = vec[i];
		if (uf.uni(x, y)) {
			ans += z;
			if (++cnt == n-1)
				break;
		}
	}
	cout << ans << '\n';

	return 0;
}
