#include <iostream>
#include <vector>
using namespace std;
#define MAX 200001
const int INF = 1e9+7;

class Segment {
public:
	int len;
	vector<int> min_tree, max_tree;

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

	int min_query(int l, int r)
	{
		l += len;
		r += len;
		int ret = INF;
		while (l <= r) {
			if (l % 2 == 1)
				ret = min(ret, min_tree[l++]);
			if (r % 2 == 0)
				ret = min(ret, min_tree[r--]);
			l /= 2;
			r /= 2;
		}
		return ret;
	}

	int max_query(int l, int r)
	{
		l += len;
		r += len;
		int ret = -INF;
		while (l <= r) {
			if (l % 2 == 1)
				ret = max(ret, max_tree[l++]);
			if (r % 2 == 0)
				ret = max(ret, max_tree[r--]);
			l /= 2;
			r /= 2;
		}
		return ret;
	}
};

int num[MAX];
int n, m, c, x, y, k;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	Segment s(n);
	for (int i=0; i<n; ++i) {
		cin >> num[i];
		num[i]--;
		s.min_tree[n+num[i]] = s.max_tree[n+num[i]] = i;
	}

	s.make();
	while (m--) {
		cin >> c >> x >> y;
		x--;
		y--;
		if (c == 1) {
			s.update(num[x], y);
			s.update(num[y], x);
			swap(num[x], num[y]);
		} else {
			if (s.max_query(x, y) - s.min_query(x, y) == y - x)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}
