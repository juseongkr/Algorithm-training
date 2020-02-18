#include <iostream>
#include <cmath>
using namespace std;
 
int t, n, d;
 
int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	cin >> t;
	while (t--) {
		cin >> n >> d;
		bool flag = false;
		for (int i=0; i<=n; ++i) {
			if (ceil((double)d / (i+1)) + i <= n) {
				flag = true;
				break;
			}
		}
 
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
 
	return 0;
}
