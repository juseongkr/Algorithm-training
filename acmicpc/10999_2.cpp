#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000001

class Lazy_Segment {
public:
	int len;
	vector<long long> tree, lazy;

	Lazy_Segment(int n) : len(n)
	{
		tree.resize(n*4, 0);
		lazy.resize(n*4, 0);
	}

	void propagation(int node, int left, int right)
	{
		if (!lazy[node])
			return;

		if (left != right) {
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		tree[node] += lazy[node] * (right - left + 1);
		lazy[node] = 0;
	}

	void _update(int node, int left, int right, int start, int end, long long val)
	{
		propagation(node, left, right);

		if (end < left || right < start)
			return;

		if (start <= left && right <= end) {
			lazy[node] += val;
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
		_update(1, 0, len-1, left, right, val);
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
		return _query(1, 0, len-1, left, right);
	}
};


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k, a, b, c, v;

	cin >> n >> m >> k;
	Lazy_Segment seg(n+1);
	for (int i=1; i<=n; ++i) {
		cin >> a;
		seg.update(i, i, a);
	}

	for (int i=0; i<m+k; ++i) {
		cin >> c;
		if (c == 1) {
			cin >> a >> b >> v;
			seg.update(a, b, v);
		} else {
			cin >> a >> b;
			cout << seg.query(a, b) << '\n';
		}
	}

	return 0;
}
