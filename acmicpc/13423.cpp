#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> vec;

int main()
{
	int t, n, k;

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; ++i) {
			cin >> k;
			vec.push_back(k);
		}

		sort(vec.begin(), vec.end());

		int cnt = 0;
		for (int i=1; i<n-1; ++i) {

			int l = 0, r = n-1;
			while (l < r) {
				int left = vec[i] - vec[l];
				int right = vec[r] - vec[i];

				if (left == right) {
					cnt++;
					l++;
				} else if (left < right) {
					r--;
				} else {
					l++;
				}
			}
		}

		cout << cnt << '\n';
		vec.clear();
	}

	return 0;
}
