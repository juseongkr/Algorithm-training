#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, t, p;

	cin >> t;
	while (t--) {
		cin >> n;
		int sum = 0, even = 0, odd = 0;
		for (int i=0; i<n; ++i) {
			cin >> p;
			if (p % 2 == 0)
				even++;
			else
				odd++;
			sum += p;
		}

		if (sum % 2) {
			cout << "YES\n";
		} else {
			if (even && odd)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}
