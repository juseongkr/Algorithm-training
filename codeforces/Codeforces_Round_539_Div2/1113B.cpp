#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n, k, sum;
vector<int> vec;

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> k;
		sum += k;
		vec.push_back(k);
	}

	sort(vec.begin(), vec.end());

	int ans = sum;
	for (int i=n-1; i>=1; i--)
		for (int j=2; j<=sqrt(vec[i]); ++j)
			if (vec[i] % j == 0)
				ans = min(ans, sum - vec[i] - vec[0] + (vec[0] * j) + (vec[i] / j));
	cout << ans << '\n';

	return 0;
}
