#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	vector<int> vec;
	int n, q, t, l, r;

	cin >> n >> q;
	for (int i=0; i<n; ++i) {
		cin >> t;
		vec.push_back(t);
	}
	sort(vec.begin(), vec.end());

	while (q--) {
		cin >> l >> r;
		int left = lower_bound(vec.begin(), vec.end(), l) - vec.begin();
		int right = upper_bound(vec.begin(), vec.end(), r) - vec.begin();
		cout << right - left << '\n';
	}

	return 0;
}
