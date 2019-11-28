#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, l, r;

	cin >> n >> l >> r;
	int x = (n - l) + (int)pow(2, l) - 1;
	int y = (int)pow(2, r) + (n-r) * (int)pow(2, (r-1)) - 1;

	cout << x << ' ' << y << '\n';

	return 0;
}
