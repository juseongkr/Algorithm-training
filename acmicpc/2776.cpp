#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n, k;

	cin >> t;
	while (t--) {
		vector<int> vec;
		cin >> n;
		for (int i=0; i<n; ++i) {
			cin >> k;
			vec.push_back(k);
		}

		sort(vec.begin(), vec.end());

		cin >> n;
		for (int i=0; i<n; ++i) {
			cin >> k;
			bool ans = false;
			int l = 0, r = vec.size()-1;
			while (l <= r) {
				int mid = (l+r)/2;
				if (vec[mid] < k) {
					l = mid+1;
				} else if (vec[mid] > k) {
					r = mid-1;
				} else {
					ans = true;
					break;
				}
			}
			if (ans)
				cout << "1\n";
			else
				cout << "0\n";
		}
	}

	return 0;
}
