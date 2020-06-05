#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class SegmentTree {
public:
	struct Node {
		int best, open, close;
		void init(Node l, Node r)
		{
			int done = min(l.open, r.close);
			best = l.best + r.best + 2*done;
			open = l.open + r.open - done;
			close = l.close + r.close - done;
		}
	};
	int len;
	vector<Node> tree;

	SegmentTree(int n) : len(n)
	{
		int h = (int)ceil(log2(len+1));
		int sz = 1 << (h+1);
		tree.resize(sz);
	}

	void init(const string &s, int node, int start, int end)
	{
		if (start == end) {
			tree[node] = {0, 0, 0};
			if (s[start] == '(')
				tree[node].open = 1;
			else
				tree[node].close = 1;
			return;
		}

		int mid = (start+end)/2;
		init(s, node*2, start, mid);
		init(s, node*2+1, mid+1, end);
		tree[node].init(tree[node*2], tree[node*2+1]);
	}

	void init(const string &s)
	{
		init(s, 1, 0, len-1);
	}

	Node query(int node, int start, int end, int i, int j)
	{
		if (i > end || j < start)
			return Node({-1, 0, 0});

		if (i <= start && end <= j)
			return tree[node];

		int mid = (start+end)/2;
		Node left = query(node*2, start, mid, i, j);
		Node right = query(node*2+1, mid+1, end, i, j);
		if (left.best == -1)
			return right;
		if (right.best == -1)
			return left;
		Node ret;
		ret.init(left, right);

		return ret;
	}

	long long query(int i, int j)
	{
		return query(1, 0, len-1, i, j).best;
	}
};

string s;
int n, m, x, y;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> s >> m;
	n = s.length();
	SegmentTree seg(n);
	seg.init(s);

	while (m--) {
		cin >> x >> y;
		cout << seg.query(x-1, y-1) << '\n';
	}

	return 0;
}
