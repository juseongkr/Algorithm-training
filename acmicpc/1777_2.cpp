#include <iostream>
using namespace std;
#define MAX 100001

int n;
int num[MAX], ans[MAX];
int tree[MAX*4];

void __update(int cur, int left, int right, int idx, int diff)
{
	if (idx < left || right < idx)
		return;

	tree[cur] += diff;
	if (left != right) {
		int mid = (left + right)/2;
		__update(2*cur, left, mid, idx, diff);
		__update(2*cur+1, mid+1, right, idx, diff);
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
	__update(1, 1, MAX, i, d);
}

int query(int k)
{
	return __query(1, 1, MAX, k);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> num[i];
		update(i, 1);
	}

	for (int i=n; i>=1; i--) {
		int idx = query(i-num[i]);
		update(idx, -1);
		ans[idx] = i;
	}

	for (int i=1; i<=n; ++i)
		cout << ans[i] << " ";

	return 0;
}
