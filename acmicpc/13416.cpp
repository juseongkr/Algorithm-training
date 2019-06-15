#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t, n, a, b, c;

	cin >> t;
	while (t--) {
		int sum = 0;
		cin >> n;
		for (int i=0; i<n; ++i) {
			cin >> a >> b >> c;
			if (a > 0 || b > 0 || c > 0)
				sum += max(a, max(b, c));
		}
		cout << sum << '\n';
	}

	return 0;
}
