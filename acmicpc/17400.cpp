#include <iostream>
using namespace std;
#define MAX 300001

int n, q, k, l, r;
long long tree[MAX*4];

void update(int i, int diff)
{
	while (i <= n) {
		tree[i] += diff;
		i += (i & -i);
	}
}

long long sum(int i)
{
	long long ret = 0;
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

	cin >> n >> q;
	for (int i=1; i<=n; ++i) {
		cin >> k;
		if (i % 2)
			k *= -1;
		update(i, k);
	}
	
	while (q--) {
		cin >> k >> l >> r;
		if (k == 1) {
			cout << abs(sum(r) - sum(l-1)) << '\n';
		} else {
			if (l % 2)
				r *= -1;
			update(l, r);
		}
	}

	return 0;
}
