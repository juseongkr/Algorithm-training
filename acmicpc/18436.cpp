#include <iostream>
#include <vector>
using namespace std;

int n, m, x, y, z, k;

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
		tree[i] = val % 2;
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

	cin >> n;
	Segment sg(n);
	for (int i=1; i<=n; ++i) {
		cin >> k;
		sg.update(i, k);
	}

	sg.make();
	cin >> m;
	while (m--) {
		cin >> z >> x >> y;
		if (z == 1)
			sg.update(x, y);
		else if (z == 2)
			cout << y-x+1-sg.query(x, y) << '\n';
		else
			cout << sg.query(x, y) << '\n';
	}

	return 0;
}
