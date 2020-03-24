#include <iostream>
#include <cmath>
using namespace std;
 
int T, n, k;
 
int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
 
	cin >> T;
	while (T--) {
		cin >> n >> k;
		if (sqrt(n) < k) {
			cout << "NO\n";
		} else if (n % 2) {
			if (k % 2)
				cout << "YES\n";
			else
				cout << "NO\n";
		} else {
			if (k % 2)
				cout << "NO\n";
			else
				cout << "YES\n";
		}
	}
 
	return 0;
}
