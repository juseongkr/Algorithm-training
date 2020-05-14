#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 200001
const int MOD = 1e9+7;

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
		init(v, 1, 1, len);
	}

	int query(int node, int start, int end, int left, int right, int k)
	{
		if (left > end || right < start)
			return 0;

		if (left <= start && end <= right) {
			return upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
		}

		int mid = (start+end)/2;
		return query(node*2, start, mid, left, right, k) + \
			query(node*2+1, mid+1, end, left, right, k);
	}

	int query(int left, int right, int k)
	{
		return query(1, 1, len, left, right, k);
	}
};

int in[MAX], out[MAX], color[MAX];
int n, m, c, x, y, num;
vector<int> graph[MAX], vec(MAX);

void dfs(int cur)
{
	in[cur] = ++num;
	vec[num] = color[cur];
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (!in[next])
			dfs(next);
	}
	out[cur] = num;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> c;
	for (int i=1; i<=n; ++i)
		cin >> color[i];

	for (int i=0; i<n-1; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(1);

	MergeSortTree sg(n+1);
	sg.init(vec);

	int ans = 0;
	while (m--) {
		cin >> x >> y;
		ans += sg.query(in[x], out[x], y);
		ans %= MOD;
	}
	cout << ans << '\n';

	return 0;
}
