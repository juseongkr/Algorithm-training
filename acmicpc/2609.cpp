#include <iostream>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) { return (a*b)/gcd(a, b); }

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);
	printf("%d\n%d\n", gcd(a, b), lcm(a, b));

	return 0;
}
