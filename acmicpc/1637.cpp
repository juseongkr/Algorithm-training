#include <iostream>
using namespace std;
#define MAX 20001
#define ll long long
const ll INF = 1e18+7;

int n;
ll a[MAX], b[MAX], c[MAX];

ll check(ll mid)
{
	ll ret = 0;
	for (int i=0; i<n; ++i)
		if (a[i] <= mid)
			ret += (min(c[i], mid) - a[i]) / b[i] + 1;

	return ret;
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i] >> c[i] >> b[i];

	ll l = 1, r = INF;
	while (l < r) {
		ll mid = (l+r)/2;
		if (check(mid) % 2)
			r = mid;
		else
			l = mid+1;
	}

	if (l == INF)
		cout << "NOTHING\n";
	else
		cout << l << " " << check(l) - check(l-1) << '\n';

	return 0;
}
