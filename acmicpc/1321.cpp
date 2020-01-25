#include <iostream>
using namespace std;
#define MAX 500001

int n, m, k, x, y;
int tree[MAX*4];

void update(int i, int diff)
{
	while (i <= n) {
		tree[i] += diff;
		i += (i & -i);
	}
}

int sum(int i)
{
	int ret = 0;
	while (i) {
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> k;
		update(i, k);
	}

	cin >> m;
	for (int i=0; i<m; ++i) {
		cin >> k;
		if (k == 1) {
			cin >> x >> y;
			update(x, y);
		} else {
			cin >> x;
			int l = 0, r = n;
			while (l <= r) {
				int mid = (l+r)/2;
				if (sum(mid) < x)
					l = mid+1;
				else
					r = mid-1;
			}
			cout << l << '\n';
		}
	}

	return 0;
}
