#include <iostream>
using namespace std;

long long solve(long long a, long long b, long long c)
{
	long long ans = 1;
	while (b) {
		if (b % 2 == 1) {
			ans *= a;
			ans %= c;
		}
		b /= 2;
		a *= a;
		a %= c;
	}
	return ans;
}

int main()
{
	long long a, b, c;

	cin >> a >> b >> c;

	cout << solve(a, b, c) << '\n';

	return 0;
}
