#include <iostream>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) { return (a*b)/gcd(a, b); }

int main()
{
	int n, a, b;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d %d", &a, &b);
		printf("%d\n", lcm(a, b));
	}

	return 0;
}
