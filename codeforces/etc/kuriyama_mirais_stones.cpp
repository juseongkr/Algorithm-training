#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long n, m, t, l, r;
	long long array[100005] = {0, };
	long long dp1[100005] = {0, };
	long long dp2[100005] = {0, };

	cin >> n;
	for (long long i=0; i<n; ++i)
		cin >> array[i];

	for (long long i=1; i<=n; ++i)
		dp1[i] = dp1[i-1] + array[i-1];

	sort(array, array + n);

	for (long long i=1; i<=n; ++i)
		dp2[i] = dp2[i-1] + array[i-1];

	cin >> m;
	for (long long i=0; i<m; ++i) {
		cin >> t >> l >> r;
		if (t == 1)
			cout << dp1[r] - dp1[l-1] << '\n';
		else
			cout << dp2[r] - dp2[l-1] << '\n';
	}

	return 0;
}
