#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 10001

int n, m, a, b, c;
int root[MAX];

class Edge {
public:
	int u, v, c;
	Edge(int x, int y, int z) : u(x), v(y), c(z) { }
	bool operator<(const Edge &a) const { return c < a.c; }
};

int find(int n)
{
	if (root[n] < 0)
		return n;
	return root[n] = find(root[n]);
}

bool uni(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return false;
	root[y] = x;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<Edge> v;
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> a >> b >> c;
		v.push_back({a, b, c});
	}

	fill(root, root+MAX, -1);
	sort(v.begin(), v.end());

	int total = 0, cnt = 0;
	for (int i=0; i<v.size(); ++i) {
		if (uni(v[i].u, v[i].v)) {
			total += v[i].c;
			if (++cnt == n-1)
				break;
		}
	}
	cout << total << '\n';

	return 0;
}
