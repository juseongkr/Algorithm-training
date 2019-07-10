#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec;
	int n, t, ans = 0;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> t;
		vec.push_back(t);
	}

	sort(vec.begin(), vec.end());

	do {
		int sum = 0;
		for (int i=1; i<n; ++i)
			sum += abs(vec[i-1] - vec[i]);
		ans = max(ans, sum);
	} while (next_permutation(vec.begin(), vec.end()));

	cout << ans << '\n';

	return 0;
}
