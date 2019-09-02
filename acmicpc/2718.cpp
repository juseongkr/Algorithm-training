#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101

long long a[MAX], b[MAX], c[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n;

	a[0] = a[1] = 1;
	b[0] = 0;
	b[1] = 1;
	c[0] = 0;
	c[1] = 1;
	for (int i=2; i<MAX; ++i) {
		a[i] = a[i-1] + a[i-2] + b[i-1] + 2 * c[i-1];
		b[i] = a[i-1] + b[i-2];
		c[i] = a[i-1] + c[i-1];
	}

	cin >> t;
	while (t--) {
		cin >> n;
		cout << a[n] << '\n';
	}

	return 0;
}
