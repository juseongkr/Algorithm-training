#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 100001
#define ll long long

int n, k;
ll tree[MAX*4], ans[MAX];
vector<pair<ll, ll>> vec;

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

ll __query(int cur, int left, int right, int start, int end)
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

ll query(int l, int r)
{
	return __query(1, 1, n, l, r);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> k;
		update(i, 1);
		vec.push_back({k, i});
	}

	sort(vec.begin(), vec.end());

	ll prev = 0, val = 0;
	for (int i=0; i<n; ++i) {
		auto [cur, idx] = vec[i];
		if (prev != cur)
			val += query(1, n) * (cur - prev);
		ans[idx] = val - query(idx+1, n);

		update(idx, -1);

		prev = cur;
	}

	for (int i=1; i<=n; ++i)
		cout << ans[i] << '\n';

	return 0;
}
