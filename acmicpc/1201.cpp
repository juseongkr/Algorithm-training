#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, m, k;

	cin >> n >> m >> k;
	if (m+k-1 > n || m*k < n) {
		cout << "-1\n";
		return 0;
	}

	vector<int> vec;
	for (int i=1; i<=n; ++i)
		vec.push_back(i);

	int l = 0;
	for (int i=1; i<=m; ++i) {
		int r = min(l+k, n-m+i);
		reverse(vec.begin() + l, vec.begin() + r);
		l = r;
	}

	for (int i=0; i<n; ++i)
		cout << vec[i] << " ";

	return 0;
}
