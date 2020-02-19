#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 10001

class Lazy_Segment {
public:
	int len;
	vector<long long> tree, lazy;

	Lazy_Segment(int n) : len(n*2)
	{
		tree.resize(MAX*8, 0);
		lazy.resize(MAX*8, 0);
	}

	void propagation(int node, int left, int right)
	{
		if (!lazy[node])
			return;

		if (left != right) {
			lazy[node*2] = 1;
			lazy[node*2+1] = 1;
		}
		tree[node] = (right - left + 1);
		lazy[node] = 0;
	}

	void _update(int node, int left, int right, int start, int end, long long val)
	{
		propagation(node, left, right);

		if (end < left || right < start)
			return;

		if (start <= left && right <= end) {
			lazy[node] = val;
			propagation(node, left, right);
			return;
		}

		int mid = (left + right) / 2;
		_update(node*2, left, mid, start, end, val);
		_update(node*2+1, mid+1, right, start, end, val);
		tree[node] = tree[node*2] + tree[node*2+1];
	}

	void update(int left, int right, long long val)
	{
		_update(1, 1, len, left, right, val);
	}

	long long _query(int node, int left, int right, int start, int end)
	{
		propagation(node, left, right);

		if (end < left || right < start)
			return 0;

		if (start <= left && right <= end)
			return tree[node];

		int mid = (left + right) / 2;
		return _query(node*2, left, mid, start, end) + _query(node*2+1, mid+1, right, start, end);
	}

	long long query(int left, int right)
	{
		return _query(1, 1, len, left, right);
	}
};

int n, x, y, ans;
vector<int> xpos, ypos, vec;

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		xpos.push_back(x);
		ypos.push_back(y);
		vec.push_back(x);
		vec.push_back(y);
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	Lazy_Segment tree = Lazy_Segment(n);
	for (int i=n-1; i>=0; i--) {
		int l = lower_bound(vec.begin(), vec.end(), xpos[i]) - vec.begin() + 1;
		int r = lower_bound(vec.begin(), vec.end(), ypos[i]) - vec.begin() + 1;

		if (tree.query(l, r) != r - l + 1)
			ans++;

		tree.update(l, r, 1);
	}
	cout << ans << '\n';

	return 0;
}
