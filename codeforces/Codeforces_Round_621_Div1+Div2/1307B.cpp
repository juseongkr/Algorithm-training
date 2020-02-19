#include <iostream>
#include <cmath>
using namespace std;

int t, n, x, k;

int main()
{
	cin >> t;
	while (t--) {
		cin >> n >> x;
		int ans = 0, flag = 0;
		for (int i=0; i<n; ++i) {
			cin >> k;
			if (k == x)
				flag = 1;
			ans = max(ans, k);
		}

		if (flag)
			cout << "1\n";
		else
			cout << max(2, (int)ceil((double)x / ans)) << '\n';
	}

	return 0;
}
