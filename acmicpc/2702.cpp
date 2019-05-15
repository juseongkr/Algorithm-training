#include <iostream>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) { return (a*b)/gcd(a, b); }

int main()
{
	int t, a, b;

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &b);

		printf("%d %d\n", lcm(a, b), gcd(a, b));
	}

	return 0;
}
