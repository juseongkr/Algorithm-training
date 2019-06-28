#include <iostream>
using namespace std;
#define MAX 1000001

int n;
long long k;
long long num[MAX];

bool check(long long t)
{
	long long ret = 0;
	for (int i=0; i<n; ++i)
		if (t > num[i])
			ret += (t - num[i]);
	if (ret <= k)
		return true;
	return false;
}

int main()
{
	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	long long ans = 1;
	long long l = 1, r = 1000000001;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (check(mid)) {
			ans = max(ans, mid);
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans << '\n';

	return 0;
}
