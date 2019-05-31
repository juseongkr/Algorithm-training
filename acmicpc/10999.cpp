#include <iostream>
using namespace std;
#define MAX 1000001
#define ll long long

ll num[MAX], tree[MAX*4], lazy[MAX*4], t;
int n, m, k, a, b, c;

ll __make(int node, int start, int end)
{
	if (start == end)
		return tree[node] = num[end];

	int mid = (start + end)/2;
	return tree[node] = __make(node*2, start, mid) + \
			    __make(node*2+1, mid+1, end);
}

void __update_lazy(int node, int start, int end)
{
	if (lazy[node] == 0)
		return;

	if (start != end) {
		lazy[node*2] += lazy[node];
		lazy[node*2+1] += lazy[node];
	}
	tree[node] += (end-start+1) * lazy[node];
	lazy[node] = 0;
}

void __update(int node, int start, int end, int left, int right, ll val)
{
	__update_lazy(node, start, end);

	if (right < start || end < left)
		return;

	if (left <= start && end <= right) {
		lazy[node] += val;
		__update_lazy(node, start, end);
		return;
	}

	int mid = (start + end)/2;
	__update(node*2, start, mid, left, right, val);
	__update(node*2+1, mid+1, end, left, right, val);
	tree[node] = tree[node*2] + tree[node*2+1];
}

ll __sum(int node, int start, int end, int left, ll right)
{
	__update_lazy(node, start, end);

	if (right < start || end < left)
		return 0;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end)/2;
	return __sum(node*2, start, mid, left, right) + \
		__sum(node*2+1, mid+1, end, left, right);
}

void make() { __make(1, 0, n-1); }
void update(int l, int r, ll val) { __update(1, 0, n-1, l, r, val); }
ll sum(int l, int r) { return __sum(1, 0, n-1, l, r); }

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i=0; i<n; ++i)
		cin >> num[i];
	
	make();
	for (int i=0; i<m+k; ++i) {
		cin >> c >> a >> b;
		if (c == 1) {
			cin >> t;
			update(a-1, b-1, t);
		} else {
			cout << sum(a-1, b-1) << '\n';
		}
	}
	return 0;
}
