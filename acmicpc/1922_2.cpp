#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int root[10002];

class Edge {
public:
	int from;
	int to;
	int cost;
};

bool cmp(Edge a, Edge b)
{
	return a.cost < b.cost;
}

int find(int n)
{
	if (n == root[n])
		return n;
	root[n] = find(root[n]);
	return root[n];
}

int main()
{
	vector<Edge> vec;
	int v, e, ans = 0;

	scanf("%d %d", &v, &e);
	for (int i=1; i<=v; ++i)
		root[i] = i;

	for (int i=0; i<e; ++i) {
		Edge E;
		scanf("%d %d %d", &E.from, &E.to, &E.cost);
		vec.push_back(E);
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i=0; i<e; ++i) {
		int from = find(vec[i].from);
		int to = find(vec[i].to);

		if (from == to)
			continue;

		root[from] = to;
		ans += vec[i].cost;
	}
	printf("%d\n", ans);

	return 0;
}
