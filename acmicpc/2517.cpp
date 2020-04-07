#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 500001

int n, k;
int tree[MAX*4], idx[MAX];
vector<pair<int, int>> vec;

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
	return __query(2*cur, left, mid, start, end) + __query(2*cur+1, mid+1, right, start, end);
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
	for (int i=0; i<n; ++i) {
		cin >> k;
		vec.push_back({k, i});
	}

	sort(vec.begin(), vec.end());
	for (int i=0; i<n; ++i)
		idx[vec[i].second] = i;

	for (int i=0; i<n; ++i) {
		cout << query(idx[i], MAX-1)+1 << '\n';
		update(idx[i], 1);
	}

	return 0;
}
