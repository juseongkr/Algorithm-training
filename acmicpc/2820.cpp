#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 500001

class Segment {
public:
	int size;
	vector<long long> tree, lazy;

	Segment(int n) : size(n)
	{
		tree.resize(n * 4, 0);
		lazy.resize(n * 4, 0);
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
		_update(1, 0, size-1, left, right, val);
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
		return _query(1, 0, size-1, left, right);
	}
};

char c;
int n, m, a, b, cnt;
int num[MAX], l[MAX], r[MAX];
vector<int> graph[MAX];

void dfs(int cur)
{
	l[cur] = ++cnt;
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		dfs(next);
	}
	r[cur] = cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> num[1];
	for (int i=2; i<=n; ++i) {
		cin >> num[i] >> a;
		graph[a].push_back(i);
	}

	dfs(1);

	Segment seg(n+1);
	for (int i=1; i<=n; ++i)
		seg.update(l[i], l[i], num[i]);

	for (int i=0; i<m; ++i) {
		cin >> c;
		if (c == 'p') {
			cin >> a >> b;
			seg.update(l[a]+1, r[a], b);
		} else {
			cin >> a;
			cout << seg.query(l[a], l[a]) << '\n';
		}
	}

	return 0;
}
