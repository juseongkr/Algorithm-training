#include <iostream>
using namespace std;
#define ll long long
const ll INF = 1e9+7;

int T;
ll n;

bool check(ll mid)
{
	return mid * (mid+1) / 2 <= n;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		ll l = 0, r = INF;
		while (l <= r) {
			ll mid = (l+r)/2;
			if (check(mid))
				l = mid+1;
			else
				r = mid-1;
		}
		cout << r << '\n';
	}

	return 0;
}
