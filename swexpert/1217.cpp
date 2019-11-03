#include <iostream>
using namespace std;

long long power(int x, int n)
{
	if (n == 0)
		return 1;

	long long ret = power(x, n/2);
	if (n % 2 == 0)
		return ret * ret;

	return ret * ret * x;
}

int main()
{
	int d, x, n;

	for (int t=1; t<=10; ++t) {
		cin >> d;
		cin >> x >> n;
		cout << "#" << t << " " << power(x, n) << '\n';
	}

	return 0;
}
