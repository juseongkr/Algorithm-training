#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
 
int main()
{
	int t, n, k;
 
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a, b;
		map<int, int> m;
		for (int i=0; i<n; ++i) {
			cin >> k;
			a.push_back(k);
		}
 
		for (int i=0; i<n; ++i) {
			cin >> k;
			b.push_back(k);
		}
 
		reverse(b.begin(), b.end());
 
		int left = 0, cnt = 0;
		for (int i=0; i<n; ++i) {
			if (a[i] == 1)
				cnt++;
			else
				cnt--;
			m[cnt] = i+1;
			if (cnt == 0)
				left = max(left , i+1);
		}
 
		cnt = 0;
		for (int i=0; i<n; ++i) {
			if (b[i] == 1)
				cnt--;
			else
				cnt++;
			if (m.count(cnt))
				left = max(left, m[cnt]+i+1);
			if (cnt == 0)
				left = max(left, i+1);
		}
 
		cout << 2 * n - left << '\n';
	}
 
	return 0;
}

