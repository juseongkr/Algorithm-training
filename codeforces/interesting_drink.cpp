#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long n, q, m, cnt;
	long long x[100005] = {0, };

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> x[i];
	cin >> q;

	sort(x, x+n);

	for (int i=0; i<q; ++i) {
		cin >> m;
		cout << upper_bound(x, x+n, m) - x << '\n';
	}

	return 0;
}
