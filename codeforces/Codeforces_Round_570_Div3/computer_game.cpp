#include <iostream>
#include <climits>
using namespace std;

long long k, n, a, b;

bool check(long long m)
{
	if ((a*m) + ((n-m)*b) < k)
		return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	
	cin >> t;
	while (t--) {
		cin >> k >> n >> a >> b;

		long long ans = -1;
		long long l = 0, r = n;
		while (l <= r) {
			long long mid = (l + r) / 2;
			if (check(mid)) {
				l = mid + 1;
				ans = max(ans, mid);
			} else {
				r = mid - 1;
			}
		}
		if (ans == -1)
			cout << "-1\n";
		else
			cout << ans << '\n';
	}

	return 0;
}
