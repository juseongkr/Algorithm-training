#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class SegmentTree {
public:
	struct Node {
		int sum = 0, min_sum = 0;
		void init(Node l, Node r)
		{
			sum = l.sum + r.sum;
			min_sum = min(l.min_sum, l.sum + r.min_sum);
		}
	};
	int len;
	vector<Node> tree;

	SegmentTree(const string &s)
	{
		len = (int)s.length();
		int h = (int)ceil(log2(len+1));
		int sz = 1 << (h+1);
		tree.resize(sz);
		init(s);
	}

	void init(const string &s, int node, int start, int end)
	{
		if (start == end) {
			if (s[start] == '(')
				tree[node] = {1, 1};
			else
				tree[node] = {-1, -1};
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

	void update(int node, int start, int end, int idx)
	{
		if (idx < start || end < idx)
			return;

		if (start == end) {
			tree[node].sum = -tree[node].sum;
			tree[node].min_sum = -tree[node].min_sum;
			return;
		}

		int mid = (start+end)/2;
		update(node*2, start, mid, idx);
		update(node*2+1, mid+1, end, idx);
		tree[node].init(tree[node*2], tree[node*2+1]);
	}

	void update(int idx)
	{
		update(1, 0, len-1, idx);
	}

	bool query()
	{
		if (tree[1].sum == 0 && tree[1].min_sum == 0)
			return true;
		return false;
	}
};

string s;
int m, idx, ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> s >> m;
	SegmentTree t(s);

	while (m--) {
		cin >> idx;
		t.update(idx-1);
		ans += t.query();
	}
	cout << ans << '\n';

	return 0;
}
