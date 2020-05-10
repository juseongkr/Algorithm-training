#include <iostream>
#include <cmath>
using namespace std;

int T, n, k;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> k;
		cout << k + (k-1)/(n-1) << '\n';
	}

	return 0;
}
