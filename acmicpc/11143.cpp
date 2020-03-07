#include <iostream>
using namespace std;
#define MAX 100001

char c;
int t, n, p, q, x, y;
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

	cin >> t;
	while (t--) {
		fill(tree, tree+MAX*4, 0);
		cin >> n >> p >> q;
		q += p;
		while (q--) {
			cin >> c >> x >> y;
			if (c == 'P') {
				update(x, y);
			} else {
				cout << sum(y) - sum(x-1) << '\n';
			}
		}
	}

	return 0;
}
