#include <iostream>
using namespace std;
#define MAX 100001

int n;
int tree[MAX*4], num[MAX], l[MAX], r[MAX];

void __update(int cur, int left, int right, int idx, int diff)
{
	if (idx < left || right < idx)
		return;

	tree[cur] += diff;
	if (left != right) {
		int mid = (left+right)/2;
		__update(2*cur, left, mid, idx, diff);
		__update(2*cur+1, mid+1, right, idx, diff);
	}
}

int __query(int cur, int left, int right, int start, int end)
{
	if (end < left || right < start)
		return 0;

	if (start <= left && right <= end)
		return tree[cur];

	int mid = (left+right)/2;
	return __query(2*cur, left, mid, start, end) + \
		__query(2*cur+1, mid+1, right, start, end);
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
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> num[i];
		l[i] = query(num[i]+1, n);
		update(num[i], 1);
	}

	fill(tree, tree+(MAX*4), 0);

	for (int i=n; i>=1; i--) {
		r[i] = query(1, num[i]-1);
		update(num[i], 1);
	}

	long long ans = 0;
	for (int i=1; i<=n; ++i)
		ans += (long long)l[i] * r[i];

	cout << ans << '\n';

	return 0;
}
