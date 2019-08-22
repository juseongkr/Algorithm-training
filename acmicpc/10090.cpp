#include <iostream>
using namespace std;
#define MAX 1000001

int tree[MAX*2];
int n, t;

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
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	long long ans = 0;
	for (int i=0; i<n; ++i) {
		cin >> t;
		update(t, 1);
		ans += (i+1) - sum(t);
	}
	cout << ans << '\n';

	return 0;
}
