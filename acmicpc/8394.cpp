#include <iostream>
using namespace std;

int n, a, b, c;

int main()
{
	cin >> n;
	b = 1;
	for (int i=1; i<=n; ++i) {
		c = (a + b) % 10;
		a = b;
		b = c;
	}
	cout << b << '\n';

	return 0;
}
