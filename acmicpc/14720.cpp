#include <iostream>
using namespace std;
#define MAX 101

int main()
{
	int n, t, k = 0, ans = 0;

	cin >> n;
	for (int i=0; i<n; ++i) { 
		cin >> t;
		if (t == k) {
			ans++;
			k = (k+1) % 3;
		}
	}
	cout << ans << '\n';

	return 0;
}
