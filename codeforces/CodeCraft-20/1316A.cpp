#include <iostream>
using namespace std;

int t, n, m, k;

int main()
{
	cin >> t;
	while (t--) {
		int sum = 0;
		cin >> n >> m;
		for (int i=0; i<n; ++i) {
			cin >> k;
			sum += k;
		}
		cout << min(m, sum) << '\n';
	}

	return 0;
}
