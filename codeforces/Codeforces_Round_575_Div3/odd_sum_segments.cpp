#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int q, n, k;
 
	cin >> q;
	while (q--) {
		cin >> n >> k;
		int odd = 0;
		vector<long long> num;
		for (int i=0; i<n; ++i) {
			long long t;
			cin >> t;
			if (t % 2 != 0)
				odd++;
			num.push_back(t);
		}

		if (odd < k || (odd - (k-1)) % 2 == 0) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			if (k != 1) {
				int cnt = 0;
				for (int i=0; i<n; ++i) {
					if (num[i] % 2 != 0) {
						cout << i+1 << " ";
						cnt++;
					}
					if (cnt == k-1)
						break;
				}
			}
			cout << n << '\n';
		}
	}
 
	return 0;
}
