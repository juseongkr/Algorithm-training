#include <iostream>
using namespace std;

int main()
{
	int t, n, cnt;

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=2; i<=n; ++i) {
			cnt = 0;
			while (n % i == 0) {
				n /= i;
				cnt++;
			}

			if (cnt)
				cout << i << " " << cnt << '\n';
		}
	}

	return 0;
}
