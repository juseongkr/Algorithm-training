#include <iostream>
using namespace std;
#define MAX 123457
#define ll long long
const ll INF = 1e18+7;

int n, Ha;
int t[MAX], a[MAX], h[MAX];

bool check(ll mid)
{
	ll Hp = mid;
	ll At = Ha;
	for (int i=0; i<n; ++i) {
		if (t[i] == 1) {
			if ((h[i]-1) / At > (Hp-1) / a[i])
				return false;
			Hp -= (h[i]-1) / At * a[i];
		} else {
			At += a[i];
			Hp = min(mid, Hp + h[i]);
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> Ha;
	for (int i=0; i<n; ++i)
		cin >> t[i] >> a[i] >> h[i];


	ll l = 1, r = INF;
	while (l <= r) {
		ll mid = (l+r)/2;
		if (check(mid))
			r = mid-1;
		else
			l = mid+1;
	}
	cout << l << '\n';

	return 0;
}
