#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1001

int t, n, m, k, x, y;
vector<pair<int, int>> vec;
int tree[MAX*4];

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
	__update(1, 1, max(n, m)+1, i, val);
}

int query(int l, int r)
{
	return __query(1, 1, max(n, m)+1, l, r);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> t;
	for (int T=1; T<=t; ++T) {
		fill(tree, tree+MAX*4, 0);
		vec.clear();
		cin >> n >> m >> k;
		for (int i=0; i<k; ++i) {
			cin >> x >> y;
			vec.push_back({x, y});
		}

		sort(vec.begin(), vec.end());

		long long ans = 0;
		for (int i=0; i<vec.size(); ++i) {
			ans += query(vec[i].second+1, max(n, m));
			update(vec[i].second, 1);
		}
		cout << "Test case " << T << ": " << ans << '\n';
	}

	return 0;
}
