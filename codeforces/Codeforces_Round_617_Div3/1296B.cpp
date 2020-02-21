#include <iostream>
#include <cmath>
using namespace std;
 
int main()
{
	int t;
	long long n;
 
	cin >> t;
	while (t--) {
		cin >> n;
		long long ans = 0;
		while (n >= 10) {
			long long p = n/10;
			ans += 10 * p;
			n -= 9 * p;
		}
		cout << ans + n << '\n';
	}
 
	return 0;
}
