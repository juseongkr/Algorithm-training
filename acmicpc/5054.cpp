#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int num[21];
	int t, n;

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; ++i)
			cin >> num[i];

		sort(num, num+n);

		int mid = (num[n-1] - num[0])/2;
		int ans = 2 * (mid-num[0]) + 2 * (num[n-1]-mid);

		cout << ans << '\n';
	}

	return 0;
}
