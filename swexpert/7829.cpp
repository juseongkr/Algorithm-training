#include <iostream>
#include <climits>
using namespace std;

int main()
{
	int t, n, k;

	cin >> t;
	for (int j=1; j<=t; ++j) {
		cin >> n;
		int min_val = INT_MAX, max_val = 0;
		for (int i=0; i<n; ++i) {
			cin >> k;
			min_val = min(min_val, k);
			max_val = max(max_val, k);
		}
		cout << "#" << j << " " << min_val * max_val << '\n';
	}

	return 0;
}
