#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define MAX 1025
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

int n, k;
vector<tp> vec;
vector<int> graph[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<=n; ++i) {
		for (int j=i+1; j<=n; ++j) {
			cin >> k;
			vec.push_back({k, i, j});
		}
	}

	sort(vec.begin(), vec.end());

	int cnt = 0;
	UnionFind uf(n);
	for (int i=0; i<vec.size(); ++i) {
		auto [z, x, y] = vec[i];
		if (uf.uni(x, y)) {
			graph[x].push_back(y);
			graph[y].push_back(x);
			if (++cnt == n-1)
				break;
		}
	}

	for (int i=1; i<=n; ++i) {
		cout << graph[i].size();
		sort(graph[i].begin(), graph[i].end());
		cout << " ";
		for (auto node : graph[i])
			cout << node << " ";
		cout << '\n';
	}

	return 0;
}
