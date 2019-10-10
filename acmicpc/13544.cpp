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

	void init(vector<int> &v, int node, int start, int end)
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

	void init(vector<int> &v)
	{
		init(v, 1, 0, len-1);
	}

	int query(int node, int start, int end, int left, int right, int k)
	{
		if (left > end || right < start)
			return 0;

		if (left <= start && end <= right) {
			return tree[node].size() - (upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin());
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

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	vector<int> vec;
	int n, x, y, k;

	cin >> n;
	MergeSortTree mst(n);
	for (int i=0; i<n; ++i) {
		cin >> k;
		vec.push_back(k);
	}
	mst.init(vec);

	cin >> n;
	int ans = 0;
	while (n--) {
		cin >> x >> y >> k;
		x = ans ^ x;
		y = ans ^ y;
		k = ans ^ k;
		ans = mst.query(x-1, y-1, k);
		cout << ans << '\n';
	}

	return 0;
}
