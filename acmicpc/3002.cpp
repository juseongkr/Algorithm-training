#include <iostream>
#include <vector>
using namespace std;

string s;
int n, m, x, y;
int temp[10];

class Lazy_Segment {
public:
	int len;
	vector<vector<int>> tree;
	vector<int> lazy;

	Lazy_Segment(int n) : len(n)
	{
		tree.resize(n*4);
		lazy.resize(n*4, 0);
		for (int i=0; i<n*4; ++i)
			tree[i].resize(10, 0);
	}

	void _init(int node, int left, int right)
	{
		if (left == right) {
			tree[node][s[left-1]-'0']++;
			return;
		}

		int mid = (left + right)/2;
		_init(node*2, left, mid);
		_init(node*2+1, mid+1, right);
		for (int i=0; i<10; ++i)
			tree[node][i] = tree[node*2][i] + tree[node*2+1][i];
	}

	void init()
	{
		_init(1, 1, len);
	}

	void propagation(int node, int left, int right)
	{
		if (!lazy[node])
			return;

		for (int i=0; i<10; ++i)
			temp[(lazy[node]+i)%10] = tree[node][i];

		for (int i=0; i<10; ++i)
			tree[node][i] = temp[i];

		if (left != right) {
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
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
		for (int i=0; i<10; ++i)
			tree[node][i] = tree[node*2][i] + tree[node*2+1][i];
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

		if (start <= left && right <= end) {
			int ret = 0;
			for (int i=0; i<10; ++i)
				ret += tree[node][i] * i;
			return ret;
		}

		int mid = (left + right) / 2;
		return _query(node*2, left, mid, start, end) + _query(node*2+1, mid+1, right, start, end);
	}

	int query(int left, int right)
	{
		return _query(1, 1, len, left, right);
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> s;
	Lazy_Segment sg(n);
	sg.init();
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		cout << sg.query(x, y) << '\n';
		sg.update(x, y, 1);
	}

	return 0;
}
