#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define MAX 300001

class UnionFind {
public:
	vector<int> p;
	UnionFind(int n)
	{
		for (int i=0; i<=n; ++i)
			p.push_back(-i);
	}

	int find(int x)
	{
		if (p[x] <= 0)
			return x;
		return p[x] = find(p[x]);
	}

	bool uni(int x, int y)
	{
		x = find(x);
		y = find(y);
		if (x == y) {
			p[x] = 0;
			return false;
		}
		p[y] = x;
		return true;
	}
};

int n, q, k;
int x[MAX], y[MAX], graph[MAX], del[MAX];
stack<int> st;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	UnionFind u = UnionFind(n+1);
	for (int i=1; i<=n; ++i)
		cin >> graph[i];

	cin >> q;
	for (int i=0; i<q; ++i) {
		cin >> x[i] >> y[i];
		if (x[i] == 2)
			del[y[i]] = 1;
	}

	for (int i=1; i<=n; ++i) {
		if (graph[i] && !del[i])
			u.uni(graph[i], i);
	}

	for (int i=q-1; i>=0; i--) {
		if (x[i] == 1)
			st.push(-u.p[u.find(y[i])]);
		else
			u.uni(graph[y[i]], y[i]);
	}

	while (!st.empty()) {
		if (st.top())
			cout << st.top() << '\n';
		else
			cout << "CIKLUS\n";
		st.pop();
	}

	return 0;
}
