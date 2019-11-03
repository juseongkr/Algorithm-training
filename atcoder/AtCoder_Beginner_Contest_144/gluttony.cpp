#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 200001

int n, t;
long long k;
vector<int> c, f;

bool check(long long m)
{
	long long ret = 0;
	for (int i=0; i<n; ++i)
		ret += max(0LL, c[i] - m/f[i]);
	return ret <= k;
}

int main()
{

	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> t;
		c.push_back(t);
	}

	for (int i=0; i<n; ++i) {
		cin >> t;
		f.push_back(t);
	}

	sort(c.rbegin(), c.rend());
	sort(f.begin(), f.end());

	long long l = 0, r = 1e18;
	while (l <= r) {
		long long mid = (l+r)/2;
		if (check(mid))
			r = mid-1;
		else
			l = mid+1;
	}
	cout << l << '\n';

	return 0;
}
