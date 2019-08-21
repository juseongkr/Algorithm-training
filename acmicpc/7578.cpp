#include <iostream>
using namespace std;
#define MAX 500001

int b[MAX*2], tree[MAX*2];
int n, m, t;

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
	for (int i=0; i<n; ++i) {
		cin >> t;
		b[t] = i+1;
	}

	long long ans = 0;
	for (int i=0; i<n; ++i) {
		cin >> t;
		ans += sum(n) - sum(b[t]);
		update(b[t], 1);
	}
	cout << ans << '\n';

	return 0;
}
