#include <iostream>
using namespace std;

long long T, x, y, a, b;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> x >> y >> a >> b;

		long long s = abs(x-y);
		long long m = min(x, y);
		cout << min(a * s + m * b, (x+y)*a) << '\n';
	}

	return 0;
}
