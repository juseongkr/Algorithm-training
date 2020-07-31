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
		int k = (n-1)/4+1;
		for (int i=0; i<n-k; ++i)
			cout << '9';
		for (int i=0; i<k; ++i)
			cout << '8';
		cout << '\n';
	}
 
	return 0;
}
