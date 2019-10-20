#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int t, n, m, k;

	cin >> t;
	while (t--) {
		set<int> a_m, b_m;
		long long a_even = 0, a_odd = 0;
		long long b_even = 0, b_odd = 0;
		cin >> n;
		for (int i=0; i<n; ++i) {
			cin >> k;
			if (!a_m.count(k)) {
				if (k % 2 == 0)
					a_even++;
				else
					a_odd++;
				a_m.insert(k);
			}
		}

		cin >> m;
		for (int i=0; i<m; ++i) {
			cin >> k;
			if (!b_m.count(k)) {
				if (k % 2 == 0)
					b_even++;
				else
					b_odd++;
				b_m.insert(k);
			}
		}

		cout << (a_even * b_even) + (a_odd * b_odd) << '\n';
	}

	return 0;
}
