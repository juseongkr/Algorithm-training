#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long a[3], d, ans = 0;

	cin >> a[0] >> a[1] >> a[2] >> d;

	sort(a, a+3);

	if (a[1] - a[0] < d)
		ans += d - (a[1] - a[0]);
	if (a[2] - a[1] < d)
		ans += d - (a[2] - a[1]);
	
	cout << ans << '\n';

	return 0;
}
