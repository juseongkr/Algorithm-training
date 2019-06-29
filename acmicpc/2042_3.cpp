#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007

class Segment {
public:
	int len;
	vector<long long> tree;

	Segment(int n) : len(n) { tree.resize(2*len); }

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

	int n, m, k, a, b, c;

	cin >> n >> m >> k;
	Segment sg(n);
	for (int i=n; i<n*2; ++i)
		cin >> sg.tree[i];

	sg.make();
	for (int i=0; i<m+k; ++i) {
		cin >> a >> b >> c;
		if (a == 1)
			sg.update(b-1, c);
		else
			cout << sg.query(b-1, c-1) << '\n';
	}
	return 0;
}
