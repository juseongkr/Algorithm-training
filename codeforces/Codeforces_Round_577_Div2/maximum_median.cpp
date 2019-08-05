#include <iostream>
#include <algorithm>
using namespace std;
 
int n, k;
long long num[200002];

bool check(long long m)
{
	long long ret = 0;
	for (int i=n/2; i<n; ++i)
		if (num[i] < m)
			ret += (m - num[i]);

	if (ret <= k)
		return true;
	return false;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	sort(num, num+n);

	long long l = num[n/2], r = 2e9+7, ans = 0;
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid)) {
			l = mid+1;
			ans = mid;
		} else {
			r = mid-1;
		}
	}
	cout << ans << '\n';
 
	return 0;
}
