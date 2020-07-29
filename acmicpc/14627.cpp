#include <iostream>
using namespace std;
#define MAX 1000001
#define ll long long
const ll INF = 1e9+7;

ll n, k, p, total;
ll pa[MAX];

bool check(ll mid)
{
	ll cnt = 0;
	for (int i=0; i<n; ++i)
		cnt += pa[i] / mid;
	return cnt >= k;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> pa[i];
		total += pa[i];
	}

	ll l = 1, r = INF;
	while (l <= r) {
		ll mid = (l+r)/2LL;
		if (check(mid)) {
			l = mid+1;
			p = mid;
		} else {
			r = mid-1;
		}
	}
	
	cout << total - k * p << '\n';

	return 0;
}
