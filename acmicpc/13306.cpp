#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define MAX 200001

class UnionFind {
public:
	vector<int> p;
	UnionFind(int n) { p.resize(n, -1); }
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

int parent[MAX], query[2*MAX][3];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, q, t;

	cin >> n >> q;
	UnionFind u = UnionFind(MAX);
	for (int i=1; i<n; ++i) {
		cin >> parent[i];
		parent[i]--;
	}
	
	q += n-1;
	for (int i=0; i<q; ++i) {
		cin >> query[i][0] >> query[i][1];
		query[i][1]--;
		if (query[i][0] == 1) {
			cin >> query[i][2];
			query[i][2]--;
		}
	}

	stack<bool> st;
	for (int i=q-1; i>=0; i--) {
		if (query[i][0] == 1) {
			if (u.find(query[i][1]) == u.find(query[i][2]))
				st.push(true);
			else
				st.push(false);
		} else {
			u.uni(query[i][1], parent[query[i][1]]);
		}
	}

	while (!st.empty()) {
		bool t = st.top();
		st.pop();
		if (t)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
