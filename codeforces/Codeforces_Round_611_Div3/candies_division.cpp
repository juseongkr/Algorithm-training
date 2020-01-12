#include <iostream>
using namespace std;

int main()
{
	int t, n, k;

	cin >> t;
	while (t--) {
		cin >> n >> k;
		cout << (n - n%k) + min(k/2, n%k) << '\n';
	}

	return 0;
}
