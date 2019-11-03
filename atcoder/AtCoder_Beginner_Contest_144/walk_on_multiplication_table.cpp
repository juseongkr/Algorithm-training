#include <iostream>
using namespace std;

int main()
{
	long long n;

	cin >> n;
	long long ans = n;
	for (long long i=1; i*i<=n; ++i)
		if (n % i == 0)
			ans = min(ans, i+n/i-2);

	cout << ans << '\n';

	return 0;
}
