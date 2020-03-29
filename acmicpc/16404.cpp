#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001

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

bool visit[MAX];
int l[MAX], r[MAX];
int n, m, cnt, k, x, y;
vector<int> graph[MAX];

void dfs(int cur)
{
	visit[cur] = 1;
	l[cur] = ++cnt;
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (!visit[next])
			dfs(next);
	}
	r[cur] = cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> k;
	Lazy_Segment sg(n);
	for (int i=2; i<=n; ++i) {
		cin >> k;
		graph[k].push_back(i);
		graph[i].push_back(k);
	}

	dfs(1);

	while (m--) {
		cin >> k;
		if (k == 1) {
			cin >> x >> y;
			sg.update(l[x], r[x], y);
		} else {
			cin >> x;
			cout << sg.query(l[x], l[x]) << '\n';
		}
	}

	return 0;
}
