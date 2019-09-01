#include <iostream>
using namespace std;

int n, m, ans;

int main()
{
	cin >> n;
	for (int i=1; i<=n; ++i) {
		m += i-1;
		if (m >= n)
			break;
		if ((n-m) % i == 0)
			ans++;
	}
	cout << ans << '\n';

	return 0;
}
