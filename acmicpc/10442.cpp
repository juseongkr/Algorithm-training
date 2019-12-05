#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, t, k;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	while (cin >> n) {
		bool flag = false;
		vector<pair<int, int>> a, b;

		for (int i=0; i<n; ++i) {
			cin >> t;
			a.push_back({t, i+1});
		}

		for (int i=0; i<n; ++i) {
			cin >> t;
			b.push_back({t, i+1});
		}

		sort(a.rbegin(), a.rend());
		sort(b.rbegin(), b.rend());

		for (int i=0; i<n; ++i) {
			if (a[i].second != b[i].second) {
				cout << "Case " << ++k << ": "<< i+1 << '\n';
				flag = true;
				break;
			}
		}

		if (!flag)
			cout << "Case " << ++k << ": agree\n";
	}

	return 0;
}
