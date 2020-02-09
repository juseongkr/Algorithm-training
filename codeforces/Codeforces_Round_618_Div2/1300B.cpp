#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int t, n, k;

	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> vec;
		for (int i=0; i<n*2; ++i) {
			cin >> k;
			vec.push_back(k);
		}

		sort(vec.begin(), vec.end());

		cout << vec[n] - vec[n-1] << '\n';
	}

	return 0;
}
