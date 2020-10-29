#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

class Lazy_Segment {
public:
	int len;
	vector<long long> tree, lazy;

	Lazy_Segment(int n) : len(n)
	{
		tree.resize(n*4, 0);
		lazy.resize(n*4, 0);
	}

	void propagation(int node)
	{
		for (int i=node*2; i<2*node+2; ++i) {
			tree[i] += lazy[node];
			lazy[i] += lazy[node];
		}
		lazy[node] = 0;
	}

	void _update(int node, int left, int right, int start, int end, long long val)
	{
		if (end < left || right < start)
			return;

		if (start <= left && right <= end) {
			lazy[node] += val;
			tree[node] += val;
			return;
		}

		int mid = (left + right) / 2;
		propagation(node);
		_update(node*2, left, mid, start, end, val);
		_update(node*2+1, mid+1, right, start, end, val);
		tree[node] = min(tree[node*2], tree[node*2+1]);
	}

	void update(int left, int right, long long val)
	{
		_update(1, 0, len-1, left, right, val);
	}
};


string s;
int m, idx, ans, sum;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> s >> m;
	int n = s.length();
	Lazy_Segment seg(n+1);
	for (int i=1; i<=n; ++i) {
		if (s[i-1] == '(') {
			seg.update(i-1, n-1, 1);
			sum++;
		} else {
			seg.update(i-1, n-1, -1);
			sum--;
		}
	}

	while (m--) {
		cin >> idx;
		idx--;
		if (s[idx] == '(') {
			seg.update(idx, n-1, -2);
			sum -= 2;
		} else {
			seg.update(idx, n-1, 2);
			sum += 2;
		}

		s[idx] = s[idx] == '(' ? ')' : '(';
		if (seg.tree[1] == 0 && sum == 0)
			ans++;
	}
	cout << ans << '\n';

	return 0;
}
