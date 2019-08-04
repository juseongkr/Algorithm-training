#include <iostream>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int main()
{
	int n, s, k, diff = 0;

	cin >> n >> s >> k;
	diff = abs(k - s);
	for (int i=0; i<n-1; ++i) {
		s = k;
		cin >> k;
		diff = gcd(diff, abs(k-s));
	}
	cout << diff << '\n';

	return 0;
}
