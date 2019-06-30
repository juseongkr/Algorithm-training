#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;

	cin >> t;
	while (t--) {
		int n;
		long long k;
		vector<long long> num;
		bool flag = false;

		cin >> n >> k;
		for (int i=0; i<n; ++i) {
			long long val;
			cin >> val;
			num.push_back(val);
		}

		sort(num.begin(), num.end());

		long long b = max(num[0] + k, num[n-1] - k);

		for (int i=0; i<n; ++i)
			if (abs(num[i] - b) > k)
				flag = true;

		if (flag)
			cout << "-1\n";
		else
			cout << b << '\n';
	}

	return 0;
}
