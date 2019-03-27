#include <iostream>
using namespace std;

int main()
{
	int k, j, x = 0;

	cin >> k;
	for (int i=k; i>=0; --i) {
		if ((i*(i+1))/2 <= k) {
			x = i;
			break;
		}
	}

	cout << x << '\n';
	for (j=0; j<x-1; ++j)
		cout << j+1 << " ";

	cout << k - (j*(j+1))/2 << '\n';

	return 0;
}
