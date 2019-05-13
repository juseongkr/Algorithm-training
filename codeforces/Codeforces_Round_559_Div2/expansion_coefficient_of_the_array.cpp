#include <iostream>
#include <climits>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int num[300001];
	int n, ans = INT_MAX;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	for (int i=0; i<n; ++i) {
		int k = num[i] / max(i, n-i-1);

		ans = min(ans, k);
	}

	cout << ans << '\n';

	return 0;
}
