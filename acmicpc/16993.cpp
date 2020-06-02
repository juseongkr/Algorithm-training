#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const long long INF = 1e18+7;

class SegmentTree {
public:
	struct Node {
		long long sum, left, right, best;
		void init(Node l, Node r)
		{
			sum = l.sum + r.sum;
			left = max(l.left, l.sum + r.left);
			right = max(r.right, l.right + r.sum);
			best = max({l.best, l.right + r.left, r.best});
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

	void init(const vector<int> &v, int node, int start, int end)
	{
		if (start == end) {
			tree[node] = {v[start], v[start], v[start], v[start]};
			return;
		}

		int mid = (start+end)/2;
		init(v, node*2, start, mid);
		init(v, node*2+1, mid+1, end);
		tree[node].init(tree[node*2], tree[node*2+1]);
	}

	void init(const vector<int> &v)
	{
		init(v, 1, 0, len-1);
	}

	Node query(int node, int start, int end, int i, int j)
	{
		if (i > end || j < start)
			return Node({0, -INF, -INF, -INF});

		if (i <= start && end <= j)
			return tree[node];

		int mid = (start+end)/2;
		Node left = query(node*2, start, mid, i, j);
		Node right = query(node*2+1, mid+1, end, i, j);
		Node ret;
		ret.init(left, right);

		return ret;
	}

	long long query(int i, int j)
	{
		return query(1, 0, len-1, i, j).best;
	}
};

vector<int> vec;
int n, m, t, x, y;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> t;
		vec.push_back(t);
	}

	SegmentTree seg(n);
	seg.init(vec);

	cin >> m;
	while (m--) {
		cin >> x >> y;
		cout << seg.query(x-1, y-1) << '\n';
	}

	return 0;
}
