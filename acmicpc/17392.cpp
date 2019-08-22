#include <iostream>
using namespace std;

int main()
{
	int n, m, t;

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> t;
		m -= t+1;
	}
	
	int ans = 0, i = 1;
	while (m > 0) {
		ans += i*i * min(m, n+1);
		m -= n+1;
		i++;
	}
	cout << ans << '\n';

	return 0;
}
