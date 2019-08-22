#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 500001

pair<int, int> a[MAX];
int tree[MAX*4];
int n;

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
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a, a+n);

	long long ans = 0;
	for (int i=0; i<n; ++i) {
		ans += sum(n - a[i].second);
		update(n - a[i].second, 1);
	}
	cout << ans << '\n';

	return 0;
}
