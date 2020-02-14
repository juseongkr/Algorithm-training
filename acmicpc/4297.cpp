#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 500001
#define ll long long

int n;
ll k;
ll tree[MAX*4];

void update(int i, ll diff)
{
	while (i <= n) {
		tree[i] += diff;
		i += (i & -i);
	}
}

ll sum(int i)
{
	ll ret = 0;
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

	while (1) {
		cin >> n;
		if (n == 0)
			break;

		fill(tree, tree+MAX*4, 0);
		vector<pair<ll, int>> vec;
		for (int i=0; i<n; ++i) {
			cin >> k;
			vec.push_back({k, i});
		}

		sort(vec.begin(), vec.end());

		long long ans = 0;
		for (int i=0; i<n; ++i) {
			ans += sum(n - vec[i].second);
			update(n - vec[i].second, 1);
		}
		cout << ans << '\n';
	}

	return 0;
}
