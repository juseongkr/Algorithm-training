#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 500001
const int INF = 1e9+7;

struct Score {
	int x, y, z;
};
int n, t;
int tree[MAX*4];
Score arr[MAX];

bool cmp(const Score &a, const Score &b) { return a.y < b.y; }

void __make(int cur, int left, int right)
{
	tree[cur] = INF;
	if (left != right) {
		int mid = (left+right)/2;
		__make(cur*2, left, mid);
		__make(cur*2+1, mid+1, right);
	}
}

void __update(int cur, int left, int right, int idx, int diff)
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

int __query(int cur, int left, int right, int start, int end)
{
	if (end < left || right < start)
		return INF;

	if (start <= left && right <= end)
		return tree[cur];

	int mid = (left+right)/2;
	return min(__query(2*cur, left, mid, start, end), __query(2*cur+1, mid+1, right, start, end));
}

void make()
{
	__make(1, 1, n);
}

void update(int i, int val)
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

	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> t;
		arr[t].x = i;
	}

	for (int i=1; i<=n; ++i) {
		cin >> t;
		arr[t].y = i;
	}

	for (int i=1; i<=n; ++i) {
		cin >> t;
		arr[t].z = i;
	}

	sort(arr+1, arr+n+1, cmp);
	make();

	int ans = 0;
	for (int i=1; i<=n; ++i) {
		int best = query(1, arr[i].x);
		if (best > arr[i].z)
			ans++;
		update(arr[i].x, arr[i].z);
	}
	cout << ans << '\n';

	return 0;
}
