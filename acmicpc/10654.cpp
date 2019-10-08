#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	long long n, t, x, y;
	vector<long long> vec;

	cin >> n >> t;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		vec.push_back(x + y * t);
	}

	long long ans = 0;
	long long stuck = vec[n-1];
	for (int i=n-1; i>=0; i--) {
		if (vec[i] < stuck)
			ans++;
		stuck = min(stuck, vec[i]);
	}
	cout << ans + 1 << '\n';

	return 0;
}
