#include <iostream>
using namespace std;
#define MAX 2000002

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int fail[MAX];

int main()
{
	int n, ans = 0;
	string a, b;
	char c;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> c;
		a += c;
	}

	for (int i=0; i<n; ++i) {
		cin >> c;
		b += c;
	}
	b = b+b;

	for (int i=1, j=0; i<n; ++i) {
		while (j && a[i] != a[j])
			j = fail[j-1];

		if (a[i] == a[j])
			fail[i] = ++j;
	}

	for (int i=0, j=0; i<n*2-1; ++i) {
		while (j && b[i] != a[j])
			j = fail[j-1];

		if (b[i] == a[j]) {
			if (j == n-1) {
				ans++;
				j = fail[j];
			} else {
				j++;
			}
		}
	}

	cout << ans/gcd(ans, n) << "/" << n/gcd(ans, n) << '\n';

	return 0;
}
