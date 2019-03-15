#include <iostream>
using namespace std;

int fact(int n)
{
	int ret = 1;
	for (int i=1; i<=n; ++i)
		ret *= i;
	return ret;
}

int main()
{
	int n, k;

	cin >> n >> k;
	cout << fact(n) / (fact(k) * fact(n-k)) << '\n';

	return 0;
}
