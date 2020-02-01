#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
long long k, extra;
vector<long long> vec;

int main()
{
	cin >> m >> n;
	for (int i=0; i<n; ++i) {
		cin >> k;
		extra += k;
		vec.push_back(k);
	}
	extra -= m;

	sort(vec.begin(), vec.end());

	long long ans = 0;
	for (int i=0; i<n; ++i) {
		long long t = min(vec[i], extra / (n-i));
		ans += t * t;
		extra -= t;
	}
	cout << ans << '\n';

	return 0;
}
