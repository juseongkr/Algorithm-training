#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 50001

char c;
int n, m, idx;
int x[MAX*5], y[MAX*5], in[MAX];
vector<int> graph[MAX*5];

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

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	UnionFind u = UnionFind(n);
	for (int i=0; i<m; ++i) {
		cin >> x[idx] >> c >> y[idx];
		if (c == '=')
			u.uni(x[idx], y[idx]);
		else
			idx++;
	}

	for (int i=0; i<idx; ++i) {
		int a = u.find(x[i]);
		int b = u.find(y[i]);
		graph[a].push_back(b);
		in[b]++;
	}

	queue<int> que;
	for (int i=0; i<n; ++i)
		if (!in[i])
			que.push(i);

	int cnt = 0;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		cnt++;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];

			if (--in[next] == 0)
				que.push(next);
		}
	}

	if (cnt == n)
		cout << "consistent\n";
	else
		cout << "inconsistent\n";

	return 0;
}
