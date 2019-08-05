#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1001

class Edge {
public:
	char color;
	int u, v;
	Edge(char c, int a, int b) : color(c), u(a), v(b) { }
};

char c;
int n, m, k, a, b;
int root[MAX];
vector<Edge> vec;

bool red(Edge &a, Edge &b)
{
	return a.color > b.color;
}

bool blue(Edge &a, Edge &b)
{
	return a.color < b.color;
}

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

int mst()
{
	int cnt = 0, ret = 0;
	fill(root, root+MAX, -1);
	for (int i=0; i<vec.size(); ++i) {
		if (uni(vec[i].u, vec[i].v)) {
			if (vec[i].color == 'B')
				ret++;
			if (++cnt == n-1)
				break;
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		cin >> n >> m >> k;
		if (!n && !m && !k)
			break;

		for (int i=0; i<m; ++i) {
			cin >> c >> a >> b;
			vec.push_back({c, a, b});
		}

		int x, y;
		sort(vec.begin(), vec.end(), red);
		x = mst();
		sort(vec.begin(), vec.end(), blue);
		y = mst();

		if (x <= k && k <= y)
			cout << "1\n";
		else
			cout << "0\n";
		vec.clear();
	}

	return 0;
}
