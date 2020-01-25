#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
 
	long long t, n;
	long long num[3];
 
	cin >> t;
	while (t--) {
		cin >> num[0] >> num[1] >> num[2] >> n;
 
		sort(num, num+3);
 
		long long x = num[2] - num[0];
		long long y = num[2] - num[1];
 
		n -= (x+y);
 
		if (n % 3 == 0 && n >= 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
 
	return 0;
}
