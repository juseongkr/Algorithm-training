#include <iostream>
using namespace std;
#define MAX 51

long long n, x;
long long p[MAX], b[MAX];

long long solve(long long n, long long x)
{
	if (n == 0 && x == 0)
		return 0;
	else if (n == 0 && x != 0)
		return 1;
	else if (x == 1)
		return 0;
	else if (x <= b[n-1] + 1)
		return solve(n-1, x-1);
	else if (x == b[n-1] + 2)
		return p[n-1] + 1;
	else if (x <= 2 * b[n-1] + 2)
		return solve(n-1, x-b[n-1]-2) + p[n-1] + 1;
	else
		return 2 * p[n-1] + 1;
}

int main()
{
	cin >> n >> x;
	p[0] = b[0] = 1;
	for (int i=1; i<=n; ++i) {
		p[i] = 2 * p[i-1] + 1;
		b[i] = 2 * b[i-1] + 3;
	}
	cout << solve(n, x) << '\n';

	return 0;
}
