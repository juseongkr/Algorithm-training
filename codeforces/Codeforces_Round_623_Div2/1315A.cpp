#include <iostream>
#include <algorithm>
using namespace std;

int T, a, b, x, y;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> a >> b >> x >> y;
		cout << max({(a-x-1)*b, a*(b-y-1), x*b, a*y}) << '\n';
	}

	return 0;
}
