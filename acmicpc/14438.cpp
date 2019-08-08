#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9+7;

class Segment {
public:
	int len;
	vector<long long> tree;

	Segment(int n) : len(n) { tree.resize(2*len); }

	void make()
	{
		for (int i=len-1; i>0; i--)
			tree[i] = min(tree[i*2], tree[i*2+1]);
	}

	void update(int i, int val)
	{
		i += len;
		tree[i] = val;
		for (i/=2; i>0; i/=2)
			tree[i] = min(tree[2*i], tree[2*i+1]);
	}

	long long query(int l, int r)
	{
		l += len;
		r += len;
		long long ret = INF;
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
	cin.tie(0);
	cout.tie(0);

	int n, q, o, a, b;

	cin >> n;
	Segment s(n);
	for (int i=n; i<n*2; ++i)
		cin >> s.tree[i];
	cin >> q;

	s.make();

	while (q--) {
		cin >> o >> a >> b;
		if (o == 1) {
			s.update(a-1, b);
		} else {
			cout << s.query(a-1, b-1) << '\n';
		}
	}

	return 0;
}
