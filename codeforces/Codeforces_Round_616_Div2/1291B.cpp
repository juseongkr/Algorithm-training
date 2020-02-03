#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t, n, k;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> vec;
		for (int i=0; i<n; ++i) {
			cin >> k;
			vec.push_back(k);
		}

		int l = 0, r = n-1;
		for (int i=0; i<n; ++i) {
			if (vec[i] >= i)
				l = i;
			else
				break;
		}

		for (int i=0; i<n; ++i) {
			if (vec[n-1-i] >= i)
				r = n-1-i;
			else
				break;
		}

		if (l < r)
			cout << "No\n";
		else
			cout << "Yes\n";
	}

	return 0;
}
