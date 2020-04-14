#include <iostream>
#include <map>
using namespace std;
 
int T, n, k;
 
int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
 
	cin >> T;
	while (T--) {
		cin >> n;
		map<int, int> mp;
		for (int i=0; i<n; ++i) {
			cin >> k;
			mp[k]++;
		}
 
		int l = 0, r = 0, idx = 0;
		for (auto i : mp) {
			if (i.second > 1) {
				r = max(r, i.second);
				idx = i.first;
			}
		}
 
		for (auto i : mp)
			if (i.first != idx)
				l++;
 
		if (r == 0) {
			if (l == 1)
				cout << "0\n";
			else
				cout << "1\n";
		} else {
			if (l < r) {
				if (r - l > 1)
					cout << l+1 << '\n';
				else
					cout << l << '\n';
			} else {
				cout << r << '\n';
			}
		}
	}
 
	return 0;
}
