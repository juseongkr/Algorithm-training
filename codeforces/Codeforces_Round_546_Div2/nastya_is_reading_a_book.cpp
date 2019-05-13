#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int r[1001];
	int n, t, k, ans = 0;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> t >> r[i];
	cin >> k;

	for (int i=0; i<n; ++i)
		if (k <= r[i])
			ans++;

	cout << ans << '\n';

	return 0;
}
