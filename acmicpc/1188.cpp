#include <iostream>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int main()
{
	int n, m, ans;

	scanf("%d %d", &n, &m);

	ans = m - gcd(n, m);
	printf("%d\n", ans);

	return 0;
}
