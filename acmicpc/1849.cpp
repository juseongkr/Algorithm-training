#include <iostream>
using namespace std;
#define MAX 100001

int n, t;
int ans[MAX], tree[MAX*4];

void __update(int cur, int left, int right, int idx, long long val)
{
	if (idx < left || right < idx)
		return;

	tree[cur] += val;
	if (left != right) {
		int mid = (left+right)/2;
		__update(2*cur, left, mid, idx, val);
		__update(2*cur+1, mid+1, right, idx, val);
	}
}

int __query(int cur, int left, int right, int k)
{
	if (left == right) {
		return left;
	} else {
		int mid = (left + right)/2;
		if (k <= tree[cur*2])
			return __query(cur*2, left, mid, k);
		else
			return __query(cur*2+1, mid+1, right, k - tree[cur*2]);
	}
}

void update(int i, int d)
{
	__update(1, 1, n, i, d);
}

int query(int k)
{
	return __query(1, 1, n, k);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i=1; i<=n; ++i)
		update(i, 1);

	for (int i=1; i<=n; ++i) {
		cin >> t;
		int p = query(t+1);
		ans[p] = i;
		update(p, -1);
	}

	for (int i=1; i<=n; ++i)
		cout << ans[i] << '\n';

	return 0;
}
