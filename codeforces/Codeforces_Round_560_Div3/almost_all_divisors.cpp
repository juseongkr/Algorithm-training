#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	long long t, n, k;

	cin >> t;
	while (t--) {
		cin >> n;
		vector<long long> vec;
		for (int i=0; i<n; ++i) {
			cin >> k;
			vec.push_back(k);
		}

		sort(vec.begin(), vec.end());

		bool flag = true;
		long long prev = vec[0] * vec[n-1];
		for (int i=1; i<n; ++i) {
			long long val = vec[i] * vec[n-1-i];
			if (prev != val) {
				flag = false;
				break;
			}
		}

		long long cnt = 0;
		for (long long i=2; i*i<=prev; ++i) {
			if (prev % i == 0)
				cnt += 2;
			if (prev == i*i)
				cnt--;
		}

		if (flag && cnt == n)
			cout << prev << '\n';
		else
			cout << "-1\n";
	}

	return 0;
}
