#include <iostream>
#include <cmath>
using namespace std;

int T, n, m, k;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> m >> k;
		if (n/k < m) {
			int left = m-n/k;
			cout << n/k - ceil((double)left/(k-1)) << '\n';
		} else {
			cout << m << '\n';
		}
	}

	return 0;
}
