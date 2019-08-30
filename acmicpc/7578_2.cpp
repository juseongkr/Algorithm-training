#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, int> b;
int a[500001];
int n, m, t;

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
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	Segment seg(n);
	for (int i=1; i<=n; ++i)
		cin >> a[i];

	seg.make();
	for (int i=1; i<=n; ++i) {
		cin >> t;
		b[t] = i;
	}

	long long ans = 0;
	for (int i=1; i<=n; ++i) {
		ans += seg.query(b[a[i]]-1, n-1);
		seg.update(b[a[i]]-1, 1);
	}
	cout << ans << '\n';

	return 0;
}
