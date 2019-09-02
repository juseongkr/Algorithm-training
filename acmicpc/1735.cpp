#include <iostream>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int main()
{
	int x1, x2, y1, y2;

	cin >> x1 >> y1 >> x2 >> y2;

	int a = x1 * y2 + y1 * x2;
	int b = y1 * y2;

	cout << a/gcd(a, b) << " " << b/gcd(a, b) << '\n';

	return 0;
}
