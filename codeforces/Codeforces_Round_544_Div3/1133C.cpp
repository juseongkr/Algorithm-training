#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, t;
	vector<int> vec;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> t;
		vec.push_back(t);
	}

	sort(vec.begin(), vec.end());

	int idx = 0, ans = 0;
	for (int i=0; i<n; ++i) {
		while (vec[idx] - vec[i] <= 5 && idx < n)
			idx++;
		ans = max(ans, idx-i);
	}
	cout << ans << '\n';

	return 0;
}
