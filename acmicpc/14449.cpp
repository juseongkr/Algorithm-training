#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Segment {
public:
	int len;
	vector<long long> tree;

	Segment(int n) : len(n) { tree.resize(2*n); }

	void make()
	{
		for (int i=len-1; i>0; i--)
			tree[i] = (tree[i*2] + tree[i*2+1]);
	}

	void update(int i, int val)
	{
		i += len;
		tree[i] = val;
		for (i/=2; i>0; i/=2)
			tree[i] = (tree[2*i] + tree[2*i+1]);
	}

	long long query(int l, int r)
	{
		l += len;
		r += len;
		long long ret = 0;
		while (l <= r) {
			if (l % 2 == 1)
				ret += tree[l++];
			if (r % 2 == 0)
				ret += tree[r--];
			l /= 2;
			r /= 2;
		}
		return ret;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	vector<pair<int, int>> vec;
	int n, t;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> t;
		vec.push_back({t, i});
	}
	sort(vec.rbegin(), vec.rend());

	int ans = 0;
	Segment seg = Segment(n);
	for (int i=0; i<n; ++i) {
		int x = vec[i].second;
		int l = seg.query(0, x);
		int r = seg.query(x, n);

		if (l*2 < r || r*2 < l)
			ans++;

		seg.update(x, 1);
	}
	cout << ans << '\n';

	return 0;
}
