#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001
#define ll long long
const int INF = 1e9+7;

class Segment {
public:
	int len;
	vector<ll> min_tree, max_tree;

	Segment(int n) : len(n)
	{
		min_tree.resize(2*len);
		max_tree.resize(2*len);
	}

	void make()
	{
		for (int i=len-1; i>0; i--) {
			min_tree[i] = min(min_tree[i*2], min_tree[i*2+1]);
			max_tree[i] = max(max_tree[i*2], max_tree[i*2+1]);
		}
	}

	void update(int i, int val)
	{
		i += len;
		min_tree[i] = max_tree[i] = val;
		for (i/=2; i>0; i/=2) {
			min_tree[i] = min(min_tree[2*i], min_tree[2*i+1]);
			max_tree[i] = max(max_tree[2*i], max_tree[2*i+1]);
		}
	}

	pair<ll, ll> query(int l, int r)
	{
		l += len;
		r += len;
		int L = l;
		int R = r;
		ll x = INF, y = -INF;
		while (l <= r) {
			if (l % 2 == 1) {
				x = min(x, min_tree[l++]);
			}
			if (r % 2 == 0) {
				x = min(x, min_tree[r--]);
			}
			l /= 2;
			r /= 2;
		}

		while (L <= R) {
			if (L % 2 == 1) {
				y = max(y, max_tree[L++]);
			}
			if (R % 2 == 0) {
				y = max(y, max_tree[R--]);
			}
			L /= 2;
			R /= 2;
		}

		return {x, y};
	}
};

int t, n, k, a, b, c;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> k;
		Segment sg(n);
		int j = 0;
		for (int i=n; i<2*n; ++i)
			sg.min_tree[i] = sg.max_tree[i] = j++;
		sg.make();

		for (int i=0; i<k; ++i) {
			cin >> c >> a >> b;
			if (c) {
				auto x = sg.query(a, b);
				if (x.first == a && x.second == b)
					cout << "YES\n";
				else
					cout << "NO\n";
			} else {
				auto x = sg.query(a, a);
				auto y = sg.query(b, b);
				sg.update(a, y.first);
				sg.update(b, x.first);
			}
		}
	}

	return 0;
}
