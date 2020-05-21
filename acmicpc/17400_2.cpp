#include <iostream>
using namespace std;
#define MAX 300001

int n, q, k, l, r;
long long tree[MAX*4];

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

long long __query(int cur, int left, int right, int start, int end)
{
	if (end < left || right < start)
		return 0;

	if (start <= left && right <= end)
		return tree[cur];

	int mid = (left+right)/2;
	return __query(2*cur, left, mid, start, end) + __query(2*cur+1, mid+1, right, start, end);
}

void update(int i, int val)
{
	__update(1, 1, n, i, val);
}

long long query(int l, int r)
{
	return __query(1, 1, n, l, r);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> q;
	for (int i=1; i<=n; ++i) {
		cin >> k;
		if (i % 2)
			k *= -1;
		update(i, k);
	}
	
	while (q--) {
		cin >> k >> l >> r;
		if (k == 1) {
			cout << abs(query(l, r)) << '\n';
		} else {
			if (l % 2)
				r *= -1;
			update(l, r);
		}
	}

	return 0;
}
