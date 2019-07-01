#include <iostream>
#include <vector>
using namespace std;

char op;
long long n, m, a, b, t;

class Segment {
public:
	int len;
	vector<long long> tree;

	Segment(int n) : len(n) { tree.resize(2*len); }

	void make()
	{
		for (int i=len-1; i>0; i--)
			tree[i] = (tree[i*2] * tree[i*2+1]);
	}

	void update(int i, int val)
	{
		i += len;
		tree[i] = val;
		for (i/=2; i>0; i/=2)
			tree[i] = (tree[2*i] * tree[2*i+1]);
	}

	long long query(int l, int r)
	{
		l += len;
		r += len;
		long long ret = 1;
		while (l <= r) {
			if (l % 2 == 1)
				ret = (ret * tree[l++]);
			if (r % 2 == 0)
				ret = (ret * tree[r--]);
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

	while (cin >> n) {
		cin >> m;
		Segment sg(n);
		for (int i=n; i<n*2; ++i) {
			cin >> t;
			if (t > 0)
				sg.tree[i] = 1;
			else if (t < 0)
				sg.tree[i] = -1;
			else
				sg.tree[i] = 0;
		}

		sg.make();
		for (int i=0; i<m; ++i) {
			cin >> op >> a >> b;
			if (op == 'C') {
				if (b > 0)
					sg.update(a-1, 1);
				else if (b < 0)
					sg.update(a-1, -1);
				else
					sg.update(a-1, 0);
			} else {
				long long ans = sg.query(a-1, b-1);
				if (ans > 0)
					cout << "+";
				else if (ans < 0)
					cout << "-";
				else
					cout << "0";
			}
		}
		cout << '\n';
	}

	return 0;
}
