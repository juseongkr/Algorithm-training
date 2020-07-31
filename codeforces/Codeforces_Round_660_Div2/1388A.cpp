#include <iostream>
using namespace std;
 
int T, n;
 
int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
 
	cin >> T;
	while (T--) {
		cin >> n;
		if (n <= 30)
			cout << "NO\n";
		else if (n == 36 || n == 44 || n == 40)
			cout << "YES\n6 10 15 " << n-31 << '\n';
		else
			cout << "YES\n6 10 14 " << n-30 << '\n';
	}
 
	return 0;
}
