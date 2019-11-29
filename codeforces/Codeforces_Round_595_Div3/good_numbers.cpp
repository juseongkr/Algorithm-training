#include <iostream>
#include <climits>
using namespace std;

long long pow[39];

int main()
{
	long long n;
	int q;

	pow[0] = 1;
	for (int i=1; i<39; ++i)
		pow[i] = pow[i-1] * 3;

	cin >> q;
	while (q--) {
		cin >> n;
		long long sum = 0, ans = LLONG_MAX;
		for (int i=38; i>=0; i--) {
			if (pow[i] >= n) {
				ans = min(ans, pow[i] + sum);
			} else {
				n -= pow[i];
				sum += pow[i];
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
