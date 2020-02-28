#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9+7;

class Lazy_Segment_Max {
public:
	int len;
	vector<int> tree, lazy;

	Lazy_Segment_Max(int n) : len(n)
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
		tree[node] += lazy[node];
		lazy[node] = 0;
	}

	void _update(int node, int left, int right, int start, int end, int val)
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
		tree[node] = max(tree[node*2], tree[node*2+1]);
	}

	void update(int left, int right, int val)
	{
		_update(1, 0, len-1, left, right, val);
	}

	int _query(int node, int left, int right, int start, int end)
	{
		propagation(node, left, right);

		if (end < left || right < start)
			return -INF;

		if (start <= left && right <= end)
			return tree[node];

		int mid = (left + right) / 2;
		return max(_query(node*2, left, mid, start, end), _query(node*2+1, mid+1, right, start, end));
	}

	int query(int left, int right)
	{
		return _query(1, 0, len-1, left, right);
	}
};

class Lazy_Segment_Min {
public:
	int len;
	vector<int> tree, lazy;

	Lazy_Segment_Min(int n) : len(n)
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
		tree[node] += lazy[node];
		lazy[node] = 0;
	}

	void _update(int node, int left, int right, int start, int end, int val)
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
		tree[node] = min(tree[node*2], tree[node*2+1]);
	}

	void update(int left, int right, int val)
	{
		_update(1, 0, len-1, left, right, val);
	}

	int _query(int node, int left, int right, int start, int end)
	{
		propagation(node, left, right);

		if (end < left || right < start)
			return INF;

		if (start <= left && right <= end)
			return tree[node];

		int mid = (left + right) / 2;
		return min(_query(node*2, left, mid, start, end), _query(node*2+1, mid+1, right, start, end));
	}

	int query(int left, int right)
	{
		return _query(1, 0, len-1, left, right);
	}
};

string s;
int c, n, o, x, y, z;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> c >> n >> o;
	Lazy_Segment_Min mi(c+1);
	Lazy_Segment_Max mx(c+1);
	for (int i=0; i<o; ++i) {
		cin >> s;
		if (s == "change") {
			cin >> x >> z;
			if (z > 0) {
				int max_val = mx.query(x, x);
				if (max_val + z > n)
					z = n - max_val;

				mi.update(x, x, z);
				mx.update(x, x, z);
				cout << z << '\n';
			} else if (z < 0) {
				int min_val = mi.query(x, x);
				if (min_val + z < 0)
					z = -min_val;

				mi.update(x, x, z);
				mx.update(x, x, z);
				cout << z << '\n';
			} else {
				cout << z << '\n';
			}
		} else if (s == "groupchange") {
			cin >> x >> y >> z;
			if (z > 0) {
				int max_val = mx.query(x, y);
				if (max_val + z > n)
					z = n - max_val;

				mi.update(x, y, z);
				mx.update(x, y, z);
				cout << z << '\n';
			} else if (z < 0) {
				int min_val = mi.query(x, y);
				if (min_val + z < 0)
					z = -min_val;

				mi.update(x, y, z);
				mx.update(x, y, z);
				cout << z << '\n';
			} else {
				cout << z << '\n';
			}
		} else {
			cin >> x;
			cout << mi.query(x, x) << '\n';
		}
	}

	return 0;
}
