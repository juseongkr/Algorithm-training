#include <iostream>
using namespace std;

long long solve(long long a, long long b, long long c)
{
	if (b == 0) {
		return 1;
	} else if (b == 1) {
		return a % c;
	} else if (b % 2 != 0) {
		return (solve(a, b-1, c) * a) % c;
	} else {
		long long t = solve(a, b/2, c);
		return (t * t) % c;
	}
}

int main()
{
	long long a, b, c;

	cin >> a >> b >> c;
	cout << solve(a, b, c) << '\n';

	return 0;
}
