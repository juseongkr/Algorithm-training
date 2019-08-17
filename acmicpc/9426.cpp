#include <iostream>
using namespace std;
#define MAX 1000001

int tree[MAX*4], t[MAX];

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
	__update(1, 0, MAX-1, i, d);
}

int query(int k)
{
	return __query(1, 0, MAX-1, k);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;

	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> t[i];

	for (int i=0; i<k; ++i)
		update(t[i], 1);

	long long ans = 0;
	long long mid = (k+1)/2;
	for (int i=0; i<n-k; ++i) {
		ans += query(mid);
		update(t[i], -1);
		update(t[i+k], 1);
	}
	ans += query(mid);
	cout << ans << '\n';

	return 0;
}
