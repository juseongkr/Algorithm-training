#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001
const int INF = 1e9+7;

int n, m, k, x, y, c, p;

class Segment {
public:
	int len;
	vector<pair<int, int>> tree;

	Segment(int n) : len(n)
	{
		tree.resize(2*n);
		for (int i=0; i<tree.size(); ++i)
			tree[i] = {INF, INF};
	}

	void make()
	{
		for (int i=len-1; i>0; i--)
			tree[i] = min(tree[i*2], tree[i*2+1]);
	}

	void update(int i, int val)
	{
		i += len;
		tree[i].first = val;
		for (i/=2; i>0; i/=2)
			tree[i] = min(tree[2*i], tree[2*i+1]);
	}

	pair<int, int> query(int l, int r)
	{
		l += len;
		r += len;
		pair<int, int> ret = {INF, INF};
		while (l <= r) {
			if (l % 2 == 1)
				ret = min(ret, tree[l++]);
			if (r % 2 == 0)
				ret = min(ret, tree[r--]);
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

	cin >> n;
	Segment seg(n);
	for (int i=n; i<2*n; ++i) {
		cin >> k;
		seg.tree[i] = {k, ++p};
	}
	seg.make();

	cin >> m;
	while (m--) {
		cin >> c >> x >> y;
		if (c == 1) {
			seg.update(x-1, y);
		} else {
			cout << seg.query(x-1, y-1).second << '\n';
		}
	}

	return 0;
}
