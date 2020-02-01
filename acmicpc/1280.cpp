#include <iostream>
using namespace std;
#define MAX 200002
#define ll long long
const ll MOD = 1e9+7;

int n, k;
ll ans = 1;
ll tree_cnt[MAX+1], tree_sum[MAX+1];

void update(int i, ll diff)
{
	while (i <= MAX) {
		tree_sum[i] += diff;
		tree_cnt[i] += 1;
		i += (i & -i);
	}
}

ll sum(int i)
{
	ll ret = 0;
	while (i) {
		ret += tree_sum[i];
		i -= (i & -i);
	}
	return ret;
}

ll cnt(int i)
{
	ll ret = 0;
	while (i) {
		ret += tree_cnt[i];
		i -= (i & -i);
	}
	return ret;
}

ll sum(int l, int r) { return sum(r) - sum(l-1); }
ll cnt(int l, int r) { return cnt(r) - cnt(l-1); }

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> k;
	k++;
	update(k, k);
	for (int i=1; i<n; ++i) {
		cin >> k;
		k++;
		ll l = k * cnt(k-1) - sum(k-1);
		ll r = sum(k+1, MAX) - k * cnt(k+1, MAX);
		ans *= (l+r) % MOD;
		ans %= MOD;
		update(k, k);
	}
	cout << ans << '\n';

	return 0;
}
