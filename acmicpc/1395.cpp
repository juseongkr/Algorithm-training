#include <iostream>
using namespace std;
#define MAX 400004

int tree[MAX], lazy[MAX];
int n, m, a, b, c;

void update_lazy(int node, int start, int end)
{
	if (!lazy[node])
		return;

	if (start != end) {
		lazy[node*2] = !lazy[node*2];
		lazy[node*2+1] = !lazy[node*2+1];
	}
	tree[node] = (end-start+1) - tree[node];
	lazy[node] = 0;
}

void update(int node, int start, int end, int left, int right)
{
	update_lazy(node, start, end);

	if (right < start || end < left)
		return;

	if (left <= start && end <= right) {
		lazy[node] = (end-start+1) - lazy[node];
		update_lazy(node, start, end);
		return;
	}

	int mid = (start + end)/2;
	update(node*2, start, mid, left, right);
	update(node*2+1, mid+1, end, left, right);
	tree[node] = tree[node*2] + tree[node*2+1];
}

int sum(int node, int start, int end, int left, int right)
{
	update_lazy(node, start, end);
    
	if (right < start || end < left)
		return 0;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end)/2;
	return sum(node*2, start, mid, left, right) + \
		sum(node*2+1, mid+1, end, left, right);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> c >> a >> b;
		if (c)
			cout << sum(1, 1, n, a, b) << '\n';
		else
			update(1, 1, n, a, b);
	}

	return 0;
}
