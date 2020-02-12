#include <iostream>
using namespace std;

int main()
{
	long long t, n, a, b;

	cin >> t;
	while (t--) {
		cin >> n >> a >> b;
		long long ans = 0;
		if (n % 2) {
			ans += a;
			n--;
		}

		cout << min(n/2*b, n*a) + ans << '\n';
	}

	return 0;
}
