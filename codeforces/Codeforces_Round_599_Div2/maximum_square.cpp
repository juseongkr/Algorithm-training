#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int q, n, t;

	cin >> q;
	while (q--) {
		cin >> n;
		vector<int> vec;
		for (int i=0; i<n; ++i) {
			cin >> t;
			vec.push_back(t);
		}

		sort(vec.rbegin(), vec.rend());

		int ans = n;
		for (int i=0; i<n; ++i) {
			if (vec[i] < i+1) {
				ans = i;
				break;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
