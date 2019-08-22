#include <iostream>
#include <climits>
using namespace std;
#define MAX 1000001
const int INF = 1e9+7;

int n, m, t, a, b;
long long tree[MAX*4];

void __update(int cur, int left, int right, int idx, long long diff)
{
	if (idx < left || right < idx)
		return;

	tree[cur] = min(tree[cur], diff);
	if (left != right) {
		int mid = (left+right)/2;
		__update(2*cur, left, mid, idx, diff);
		__update(2*cur+1, mid+1, right, idx, diff);
	}
}

long long __query(int cur, int left, int right, int start, int end)
{
	if (end < left || right < start)
		return INF;

	if (start <= left && right <= end)
		return tree[cur];

	int mid = (left+right)/2;
	return min(__query(2*cur, left, mid, start, end), __query(2*cur+1, mid+1, right, start, end));
}

void update(int i, long long val)
{
	__update(1, 1, n, i, val);
}

int query(int l, int r)
{
	return __query(1, 1, n, l, r);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i=0; i<MAX*4; ++i)
		tree[i] = INF;

	cin >> n >> m;
	for (int i=1; i<=n; ++i) {
		cin >> t;
		update(i, t);
	}

	for (int i=0; i<m; ++i) {
		cin >> a >> b;
		cout << query(a, b) << '\n';
	}

	return 0;
}
