#include <iostream>
using namespace std;
#define MAX 1000001

int n, a, b, c;
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
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a;
		if (a == 1) {
			cin >> b;
			int t = query(b);
			cout << t << '\n';
			update(t, -1);
		} else {
			cin >> b >> c;
			update(b, c);
		}
	}

	return 0;
}
