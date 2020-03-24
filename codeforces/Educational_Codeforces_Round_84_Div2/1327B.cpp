#include <iostream>
#include <set>
using namespace std;
#define MAX 100002
 
int T, n, k, p[MAX];
 
int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
 
	cin >> T;
	while (T--) {
		cin >> n;
		set<int> L, R;
		for (int i=0; i<n; ++i) {
			L.insert(i+1);
			R.insert(i+1);
		}
 
		bool ans = false;
		for (int i=0; i<n; ++i) {
			cin >> k;
			for (int j=0; j<k; ++j)
				cin >> p[j];
 
			for (int j=0; j<k; ++j) {
				if (R.count(p[j])) {
					L.erase(i+1);
					R.erase(p[j]);
					break;
				}
			}
		}
 
		if (R.size()) {
			cout << "IMPROVE\n";
			cout << *L.begin() << " " << *R.begin() << '\n';
		} else {
			cout << "OPTIMAL\n";
		}
	}
 
	return 0;
}
