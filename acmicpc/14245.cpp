#include <iostream>
#include <vector>
using namespace std;
#define MAX 500001

int n, m, a, b, c, k;

class Lazy_Segment {
public:
	int len;
	vector<int> tree, lazy;

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
			lazy[node*2] ^= lazy[node];
			lazy[node*2+1] ^= lazy[node];
		}
		tree[node] ^= (right-left+1)%2 * lazy[node];
		lazy[node] = 0;
	}

	void _update(int node, int left, int right, int start, int end, int val)
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
		tree[node] = tree[node*2] ^ tree[node*2+1];
	}

	void update(int left, int right, int val)
	{
		_update(1, 1, len, left, right, val);
	}

	int _query(int node, int left, int right, int start, int end)
	{
		propagation(node, left, right);

		if (end < left || right < start)
			return 0;

		if (start <= left && right <= end)
			return tree[node];

		int mid = (left + right) / 2;
		return _query(node*2, left, mid, start, end) ^ _query(node*2+1, mid+1, right, start, end);
	}

	int query(int left, int right)
	{
		return _query(1, 1, len, left, right);
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	Lazy_Segment seg(n);
	for (int i=1; i<=n; ++i) {
		cin >> a;
		seg.update(i, i, a);
	}

	cin >> m;
	while (m--) {
		cin >> k;
		if (k == 1) {
			cin >> a >> b >> c;
			a++;
			b++;
			seg.update(a, b, c);
		} else {
			cin >> a;
			a++;
			cout << seg.query(a, a) << '\n';
		}
	}

	return 0;
}
