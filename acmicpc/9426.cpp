#include <iostream>
using namespace std;
#define MAX 1000001

int tree[MAX*4], t[MAX];

void update(int node, int left, int right, int idx, int val)
{
	if (idx < left || idx > right)
		return;

	if (left == right) {
		tree[node] += val;
		return;
	}
	int mid = (left+right)/2;
	update(node*2, left, mid, idx, val);
	update(node*2+1, mid+1, right, idx, val);
	tree[node] = tree[node*2] + tree[node*2+1];
}

int query(int node, int left, int right, int k)
{
	if (left == right) {
		return left;
	} else {
		int mid = (left+right)/2;
		if (k <= tree[node*2])
			return query(node*2, left, mid, k);
		else
			return query(node*2+1, mid+1, right, k-tree[node*2]);
	}
}

int main()
{
	int n, k;
	long long ans = 0;

	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> t[i];

	for (int i=0; i<k; ++i)
		update(1, 0, MAX-1, t[i], 1);

	long long mid = (k+1)/2;
	for (int i=0; i<n-k; ++i) {
		ans += query(1, 0, MAX-1, mid);
		update(1, 0, MAX-1, t[i], -1);
		update(1, 0, MAX-1, t[i+k], 1);
	}
	ans += query(1, 0, MAX-1, mid);
	cout << ans << '\n';

	return 0;
}
