#include <iostream>
using namespace std;
#define MAX 1000001

int num[MAX], tree[MAX*4], lazy[MAX*4];
int n, m, k, a, b, c, t;

int __make(int node, int start, int end)
{
	if (start == end)
		return tree[node] = num[end];

	int mid = (start + end)/2;
	return tree[node] = __make(node*2, start, mid) ^ \
			    __make(node*2+1, mid+1, end);
}

void __update_lazy(int node, int start, int end)
{
	if (!lazy[node])
		return;

	if (start != end) {
		lazy[node*2] ^= lazy[node];
		lazy[node*2+1] ^= lazy[node];
	}
	tree[node] ^= (end-start+1)%2 * lazy[node];
	lazy[node] = 0;
}

int __update(int node, int start, int end, int left, int right, int val)
{
	__update_lazy(node, start, end);

	if (right < start || end < left)
		return tree[node];

	if (left <= start && end <= right) {
		if (start != end) {
			lazy[node*2] ^= val;
			lazy[node*2+1] ^= val;
		}
		tree[node] ^= (end-start+1)%2 * val;
		return tree[node];
	}

	int mid = (start + end)/2;
	return tree[node] = __update(node*2, start, mid, left, right, val) ^ \
			    __update(node*2+1, mid+1, end, left, right, val);
}

int __get_xor(int node, int start, int end, int left, int right)
{
	__update_lazy(node, start, end);

	if (right < start || end < left)
		return 0;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end)/2;
	return __get_xor(node*2, start, mid, left, right) ^ \
		__get_xor(node*2+1, mid+1, end, left, right);
}

void make() { __make(1, 0, n-1); }
int update(int l, int r, int val) { return __update(1, 0, n-1, l, r, val); }
int get_xor(int l, int r) { return __get_xor(1, 0, n-1, l, r); }

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];
	
	make();
	cin >> m;
	for (int i=0; i<m; ++i) {
		cin >> t >> a >> b;
		if (a > b)
			swap(a, b);
		if (t == 1) {
			cin >> c;
			update(a, b, c);
		} else {
			cout << get_xor(a, b) << '\n';
		}
	}
	return 0;
}
