#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001

int n;
int num[MAX], ans[MAX];

class Segment {
public:
	int len;
	vector<int> tree;

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

	int query(int l, int r)
	{
		l += len;
		r += len;
		int ret = 0;
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
		cin >> num[i];
		sg.update(i, 1);
	}

	sg.make();
	for (int i=n; i>=1; i--) {
		int l = 1, r = n+1;
		while (l <= r) {
			int mid = (l+r)/2;
			if (sg.query(mid, n+1) <= num[i])
				r = mid-1;
			else
				l = mid+1;
		}
		sg.update(r, 0);
		ans[r] = i;
	}

	for (int i=1; i<=n; ++i)
		cout << ans[i] << " ";

	return 0;
}
