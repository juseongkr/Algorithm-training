#include <iostream>
using namespace std;

long long gcd(long long a, long long b) { return b ? gcd(b, a%b) : a; }

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n, m, sx, sy, ex, ey, q;

	cin >> n >> m >> q;
	long long gc = gcd(n, m);
	while (q--) {
		cin >> sx >> sy >> ex >> ey;

		if (sx == 1)
			sy = (sy-1) / (n/gc);
		else
			sy = (sy-1) / (m/gc);

		if (ex == 1)
			ey = (ey-1) / (n/gc);
		else
			ey = (ey-1) / (m/gc);

		if (sy == ey)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
