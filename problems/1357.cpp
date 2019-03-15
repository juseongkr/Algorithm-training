#include <iostream>
using namespace std;

int rev(int n)
{	
	int ret = 0;
	while (n) {
		ret *= 10;
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main()
{
	int x, y;

	cin >> x >> y;
	cout << rev(rev(x) + rev(y)) << '\n';

	return 0;
}
