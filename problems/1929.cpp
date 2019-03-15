#include <iostream>
#include <cmath>
using namespace std;

bool check(int n)
{
	if (n < 2)
		return 0;

	for (int i=2; i<=sqrt(n); ++i)
		if (n % i == 0)
			return 0;

	return 1;
}

int main()
{
	int a, b;
	
	cin >> a >> b;
	for (int i=a; i<=b; ++i) {
		if (check(i))
			cout << i << '\n';
	}

	return 0;
}
