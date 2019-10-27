#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10001

int num[MAX];

int main()
{
	int t, n;

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; ++i)
			cin >> num[i];

		sort(num, num+n);

		int ans = 0;
		for (int i=2; i<n; ++i)
			ans = max(ans, num[i] - num[i-2]);

		cout << ans << '\n';
	}

	return 0;
}
