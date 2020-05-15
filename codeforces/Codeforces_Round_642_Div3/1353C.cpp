#include <iostream>
using namespace std;

int T;
long long n;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		long long ans = 0;

		long long m = (n-1)/2;
		ans += 4 * m * (m+1) / 2;

		long long k = 1, temp = 0;
		for (int i=1; i<=m; ++i) {
			temp += k * i;
			k += 2;
		}
		ans += temp * 4;
		
		cout << ans << '\n';
	}

	return 0;
}
