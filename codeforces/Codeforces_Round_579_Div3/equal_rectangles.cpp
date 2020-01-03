#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int t, n, k;

	cin >> t;
	while (t--) {
		vector<int> vec;
		cin >> n;
		for (int i=0; i<4*n; ++i) {
			cin >> k;
			vec.push_back(k);
		}

		sort(vec.begin(), vec.end());

		bool flag = false;
		for (int i=1; i<4*n; i+=2) {
			if (vec[i-1] != vec[i]) {
				flag = true;
				break;
			}
		}
		if (flag) {
			cout << "NO\n";
			continue;
		}

		int l = 0, r = 4*n-1;
		int area = vec[l] * vec[r];
		while (l < r) {
			if (vec[l] * vec[r] != area) {
				flag = true;
				break;
			}
			l += 2;
			r -= 2;
		}
		if (flag)
			cout << "NO\n";
		else
			cout << "YES\n";
	}

	return 0;
}
