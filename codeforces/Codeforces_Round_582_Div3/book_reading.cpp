#include <iostream>
using namespace std;

long long a[11], s[11];

int main()
{
	long long n, m;
	int q;

	cin >> q;
	while (q--) {
		cin >> n >> m;
		for (int i=1; i<=10; ++i) {
			a[i] = (m * i) % 10;
			s[i] = s[i-1] + a[i];
		}
		cout << (n/m/10) * s[10] + s[n/m%10] << '\n';
	}

	return 0;
}
