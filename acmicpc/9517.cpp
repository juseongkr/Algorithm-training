#include <iostream>
using namespace std;

int main()
{
	char z;
	int k, n, t;
	int sum = 0;

	cin >> k >> n;
	for (int i=0; i<n; ++i) {
		cin >> t >> z;
		sum += t;
		if (sum >= 210)
			break;
		if (z == 'T')
			k++;
		if (k > 8)
			k %= 8;
	}
	cout << k << '\n';

	return 0;
}
