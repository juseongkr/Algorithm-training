#include <iostream>
using namespace std;

int main()
{
	long long n, m, k, l, t;
	
	cin >> n >> m >> k >> l;

	t = (m + k + l - 1) / m;

	if (t * m > n)
		cout << -1 << '\n';
	else
		cout << t << '\n';

	return 0;
}
