#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class MergeSortTree {
public:
	int len;
	vector<vector<int>> tree;

	MergeSortTree(int n) : len(n)
	{
		int h = (int)ceil(log2(n+1));
		int sz = (1 << (h+1));
		tree.resize(sz);
	}

	void init(const vector<int> &v, int node, int start, int end)
	{
		if (start == end) {
			tree[node].push_back(v[start]);
			return;
		}
		int mid = (start+end)/2;

		init(v, node*2, start, mid);
		init(v, node*2+1, mid+1, end);
		merge(tree[node*2].begin(), tree[node*2].end(), \
		tree[node*2+1].begin(), tree[node*2+1].end(), back_inserter(tree[node]));
	}

	void init(const vector<int> &v)
	{
		init(v, 1, 0, len-1);
	}

	int query(int node, int start, int end, int left, int right, int k)
	{
		if (left > end || right < start)
			return 0;

		if (left <= start && end <= right) {
			return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
		}

		int mid = (start+end)/2;
		return query(node*2, start, mid, left, right, k) + \
			query(node*2+1, mid+1, end, left, right, k);
	}

	int query(int left, int right, int k)
	{
		return query(1, 0, len-1, left, right, k);
	}
};

int n, q, x, y, z, k;
vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	MergeSortTree sg(n);
	for (int i=0; i<n; ++i) {
		cin >> k;
		vec.push_back(k);
	}

	sg.init(vec);

	cin >> q;
	while (q--) {
		cin >> x >> y >> z;
		cout << sg.query(x-1, y-1, z) << '\n';
	}

	return 0;
}
