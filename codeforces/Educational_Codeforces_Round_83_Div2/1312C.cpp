#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const long long MAX = 1e16+7;

long long p;
int T, n, k;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> k;
		vector<long long> num;

		for (int i=0; i<n; ++i) {
			cin >> p;
			num.push_back(p);
		}

		if (k == 1) {
			cout << "YES\n";
			continue;
		}

		long long v = 0;
		for (v=1; v<MAX; v*=k);

		while (v) {
			for (int i=0; i<n; ++i) {
				if (num[i] >= v) {
					num[i] -= v;
					break;
				}
			}
			v /= k;
		}

		sort(num.begin(), num.end());

		if (num[n-1])
			cout << "NO\n";
		else
			cout << "YES\n";
	}

	return 0;
}
