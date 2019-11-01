#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define MAX 27

class UnionFind {
public:
	vector<int> p;
	UnionFind(int n) { p.resize(MAX+1, -1); }
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

int main()
{
	vector<tuple<int, int, int>> vec;
	int n, w, cnt;
	char c, d;

	while (1) {
		cin >> n;
		if (n == 0)
			break;

		for (int i=0; i<n-1; ++i) {
			cin >> d >> cnt;
			for (int j=0; j<cnt; ++j) {
				cin >> c >> w;
				vec.push_back({w, i, c-'A'});
			}
		}
		sort(vec.begin(), vec.end());

		int ans = 0, cnt = 0;
		UnionFind u = UnionFind(n);
		for (int i=0; cnt<n-1; ++i) {
			auto [c, a, b] = vec[i];
			if (u.uni(a, b)) {
				ans += c;
				cnt++;
			}
		}
		cout << ans << '\n';
		vec.clear();
	}

	return 0;
}
